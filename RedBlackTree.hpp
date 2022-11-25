/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:18:07 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 10:20:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"

#include <memory>
#include <limits>
#include <iterator>
#include <cstddef>

#ifndef nullptr
# define nullptr NULL
#endif

namespace ft {
	enum Color { black = true, red = false };

	template <typename T>
	class Node {
		public:
			typedef T 															value_type;
			typedef Node<value_type>*											node_ptr;
			typedef const Node<value_type>*										const_node_ptr;
		
		Node() : _color(black),  _value(), _parent(), _left(), _right() {};
		Node(const Node& other) : _color(other._color), _value(other._value), _parent(other._parent), _left(other._left), _right(other._right) {};
		~Node() {};
		Node& operator=(const Node& other) {
			if (this != &other) {
				_color = other._color;
				_value = other._value;
				_parent = other._parent;
				_left = other._left;
				_right = other._right;
		}
			return *this;
		}
		
		void	color_swap(){
		this->_color = this->_color == red ? black : red;
		}
		
		public:
			Color		_color;
			value_type	_value;
			node_ptr	_parent;
			node_ptr	_left;
			node_ptr	_right;
	};

//Checking if the node is a left child of its parent.
	template <typename T>
	bool is_left_child(typename Node<T>::node_ptr node) {
		if (!node || !node->_parent || !node->_parent->_left)
			return false;
		if (node->_parent->_left == node && node->_parent->_left)
			return true;
		return false;
	} 
	template <typename T>
	bool is_left_child(typename Node<T>::const_node_ptr node) {
		if (!node || !node->_parent || !node->_parent->_left)
			return false;
		if (node->_parent->_left == node && node->_parent->_left != nullptr)
			return true;
		return false;
	}
//Finding the minimum value in the tree.
	template <typename T>
	typename Node<T>::node_ptr tree_min(typename Node<T>::node_ptr node) {
		while (node->_left != nullptr)
			node = node->_left;
		return node;
	}
	template <typename T>
	typename Node<T>::const_node_ptr tree_min(typename Node<T>::const_node_ptr node) {
		while (node->_left != nullptr)
			node = node->_left;
		return node;
	}
//Finding the maximum value in the tree.
	template <typename T>
	typename Node<T>::node_ptr tree_max(typename Node<T>::node_ptr node) {
		while (node->_right != nullptr)
			node = node->_right;
		return node;
	}
	template <typename T>
	typename Node<T>::const_node_ptr tree_max(typename Node<T>::const_node_ptr node) {
		while (node->_right != nullptr)
			node = node->_right;
		return node;
	}
	template <typename Node_ptr, typename Value>
	class RBT_iterator {
		public:
			typedef bidirectional_iterator_tag									iterator_category;
			typedef Value														value_type;
			typedef Value&														reference;
			typedef Value*														pointer;
			typedef ptrdiff_t													difference_type;
		public:
			RBT_iterator() : _current() {};
			RBT_iterator(const Node_ptr& ptr) : _current(ptr) {};
			RBT_iterator(const RBT_iterator& other) : _current(other._current) {};
			RBT_iterator& operator=(const RBT_iterator& other) {
				if (this != &other)
					this->_current = other._current;
				return *this;
			}
			RBT_iterator& operator=(const Node_ptr& ptr) {
				this->_current = ptr;
				return *this;
			}
			RBT_iterator& operator++() {
				if (_current->_right != nullptr && _current->_right != nullptr && _current != nullptr) {
					_current = tree_min<value_type>(_current->_right);
				} 
				else {
					while (!is_left_child<value_type>(_current) && _current->_parent != nullptr && _current->_parent->_right == _current) {
						_current = _current->_parent;
					}
					_current = _current->_parent;
				}
				return *this;
			}
			RBT_iterator& operator--() {
				if (_current->_left != nullptr) {
					_current = tree_max<value_type>(_current->_left);
				} 
				else {
					while (is_left_child<value_type>(_current))
						_current = _current->_parent;
					_current = _current->_parent;
				}
				return *this;
			}
			RBT_iterator operator++(int) {
				RBT_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			RBT_iterator operator--(int){
				RBT_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			reference operator*() const {
				return _current->_value;
			}
			pointer operator->() const {
				return &_current->_value;
			}
			Node_ptr base() const {
				return _current;
			}
		private:
			Node_ptr _current;
	};
	
	template <typename Node_ptr, typename Value>
	bool operator==(const RBT_iterator<Node_ptr, Value>& lhs, const RBT_iterator<Node_ptr, Value>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <typename Node_ptr, typename Value>
	bool operator!=(const RBT_iterator<Node_ptr, Value>& lhs, const RBT_iterator<Node_ptr, Value>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename Const_node_ptr, typename Value>
	class const_RBT_iterator {
		public:
			typedef bidirectional_iterator_tag									iterator_category;
			typedef Value														value_type;
			typedef const Value&												reference;
			typedef const Value*												pointer;
			typedef ptrdiff_t													difference_type;
		private:
			typedef RBT_iterator<typename Node<Value>::node_ptr, Value>			normal_iterator;
		public:
			const_RBT_iterator() : _current() {};
			const_RBT_iterator(const const_RBT_iterator& other) : _current(other._current) {};
			const_RBT_iterator(const normal_iterator& other) : _current(other.base()) {};
			const_RBT_iterator(const Const_node_ptr& ptr) : _current(ptr) {};
			const_RBT_iterator& operator=(const const_RBT_iterator& other) {
				if (this != &other)
					this->_current = other._current;
				return *this;
			}
			const_RBT_iterator& operator=(const Const_node_ptr& ptr) {
				this->_current = ptr;
				return *this;
			}
			const_RBT_iterator& operator++() {
				if (_current->_right != nullptr) {
					_current = tree_min<value_type>(_current->_right);
				} 
				else {
					while (!is_left_child<value_type>(_current)) {
						_current = _current->_parent;
					}
					_current = _current->_parent;
				}
				return *this;
			}
			const_RBT_iterator operator++(int) {
				const_RBT_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			const_RBT_iterator& operator--() {
				if (_current->_left != nullptr) {
					_current = tree_max<value_type>(_current->_left);
				} 
				else {
					while (is_left_child<value_type>(_current))
						_current = _current->_parent;
					_current = _current->_parent;
				}
				return *this;
			}
			const_RBT_iterator operator--(int) {
				const_RBT_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			reference operator*() const {
				return _current->_value;
			}
			pointer operator->() const {
				return &_current->_value;
			}
			Const_node_ptr base() const {
				return _current;
			}
		private:
			Const_node_ptr _current;
	};

	template <typename Const_node_ptr, typename Value>
	bool operator==(const const_RBT_iterator<Const_node_ptr, Value>& lhs, 
					const const_RBT_iterator<Const_node_ptr, Value>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <typename Const_node_ptr, typename Value>
	bool operator!=(const const_RBT_iterator<Const_node_ptr, Value>& lhs, 
					const const_RBT_iterator<Const_node_ptr, Value>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <typename Const_node_ptr, typename Node_ptr, typename Value>
	bool operator==(const const_RBT_iterator<Const_node_ptr, Value>& lhs, 
					const RBT_iterator<Node_ptr, Value>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <typename Const_node_ptr, typename Node_ptr, typename Value>
	bool operator!=(const const_RBT_iterator<Const_node_ptr, Value>& lhs, 
					const RBT_iterator<Node_ptr, Value>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <typename Const_node_ptr, typename Node_ptr, typename Value>
	bool operator==(const RBT_iterator<Node_ptr, Value>& lhs, 
					const const_RBT_iterator<Const_node_ptr, Value>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <typename Const_node_ptr, typename Node_ptr, typename Value>
	bool operator!=(const RBT_iterator<Node_ptr, Value>& lhs, 
					const const_RBT_iterator<Const_node_ptr, Value>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <typename T, typename Compare, typename Alloc>
	class RedBlackTree {
		private:
			typedef Node<T>															node_type;
		public:
			typedef T																value_type;
			typedef Compare															value_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other		node_allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference 						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer 							const_pointer;
			typedef typename allocator_type::size_type								size_type;
			typedef typename allocator_type::difference_type						difference_type;
			typedef typename node_type::node_ptr									node_ptr;
			typedef typename node_type::const_node_ptr								const_node_ptr;
			
			typedef RBT_iterator<node_ptr, value_type>								iterator;
			typedef const_RBT_iterator<const_node_ptr, value_type>					const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;	
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
		
		private:
			size_type 			_size;
			node_type 			_parent;
			node_ptr			_begin;
			value_compare 		_comp;
			allocator_type 		_alloc;
			node_allocator_type _node_alloc;

		public:
		//Construct
			explicit RedBlackTree(const value_compare& comp, const allocator_type& alloc) : 
				_size(), _parent(), _begin(&_parent), _comp(comp), _alloc(alloc), _node_alloc(alloc) {};
			// - Copy
			RedBlackTree(const RedBlackTree& other) : 
				_size(), _parent(), _begin(&_parent), _comp(other._comp), _alloc(other._alloc), _node_alloc(other._node_alloc) {
					if (other._root() != nullptr) {
						this->_root() = this->_copy_node(other._root());
						this->_root()->_parent = &this->_parent;
					}
				}
		//Assign
			RedBlackTree& operator=(const RedBlackTree& other) {
				if (this != &other) {
					this->clear();
					this->_comp = other._comp;
					if (other._root() != nullptr) {
						this->_root() = this->_copy_node(other._root());
						this->_root()->_parent = &this->_parent;
					}
				}
				return *this;
			}
		//Destruct
			~RedBlackTree()  {
				if (this->_root() != nullptr) {
					this->_clear(this->_root());
					this->_root() = nullptr;
					this->_begin = this->_end_tree();
				}
			}
		//Iterators
			iterator begin() { return iterator(this->_begin); }
			const_iterator begin() const { return const_iterator(this->_begin); }
			iterator end() { return iterator(&this->_parent); }
			const_iterator end() const { return const_iterator(&this->_parent); }
		//Reverse iterators
			reverse_iterator rbegin() { return reverse_iterator(this->end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
			reverse_iterator rend() { return reverse_iterator(this->begin()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
		//Capacity
			bool empty() const { return this->_size == 0; }
			size_type size() const { return this->_size; }
			size_type max_size() const { return node_allocator_type().max_size(); }
		//Modifiers
			//Inserting a new node into the tree.
			ft::pair<iterator, bool> insert(const value_type& val) {
				node_ptr new_node = this->_new_node(val);
				bool i = false;
				iterator pos;
				this->_root() = this->_insert_node(this->_root(), new_node, i, pos);
				this->_root()->_parent = &this->_parent;
				if (!i) 
					this->_delete_node(new_node);
				else
					this->_balance_insert(new_node);
				this->_root()->_color = black;
				return ft::make_pair(pos, i);
			}
			iterator insert(__attribute__((unused)) iterator pos, const value_type& val) {
				//(void)pos;
				return this->insert(val).first;
			}
			template <typename InputIterator>
				void insert(InputIterator first, InputIterator last) {
				for (; first != last; ++first)
					this->insert(*first);
			}
			void erase(iterator pos) {
				node_ptr to_delete = pos.base();
				if (to_delete == this->_begin) {
					++pos;
					this->_begin = pos.base();
				}
				this->_erase(this->_root(), to_delete);
				if (this->_root() != nullptr) {
					this->_root()->_parent = this->_end_tree();
					this->_root()->_color = black;
				}
				this->_delete_node(to_delete);
			}
			size_type erase(const value_type& val) {
				iterator to_delete = this->find(val);
				if (to_delete == this->end())
					return 0;
				this->erase(to_delete);
				return 1;
			}
			void erase(iterator first, iterator last) {
				while (first != last) {
					this->erase(first++);
				}
			}
			void clear() {
				if (this->_root() != nullptr) {
					this->_clear(this->_root());
					this->_root() = nullptr;
					this->_begin = this->_end_tree();
				}
			}
			void swap(RedBlackTree& other) {
				if (other._root() == nullptr) {
					RedBlackTree tmp(other);
					other = *this;
					*this = tmp;
					return;
				}
				ft::swap(this->_begin, other._begin);
				ft::swap(this->_parent._left, other._parent._left);
				ft::swap(this->_size, other._size);
				if (this->_size != 0 && other._size != 0)
					ft::swap(this->_root()->_parent, other._root()->_parent);
				else if (this->_size != 0)
					this->_root()->_parent = this->_end_tree();
				else if (other._size != 0)
					other._root()->_parent = other._end_tree();
				ft::swap(this->_comp, other._comp);
			}
		//Lookup
			value_compare value_cmp() const { return this->_comp; }
		//Operations
			iterator find(const value_type& val) {
				node_ptr found = this->_root();
				while (found != nullptr) {
					if (this->_comp(val, found->_value))
						found = found->_left;
					else if (this->_comp(found->_value, val))
						found = found->_right;
					else
						return iterator(found);
				}
				return this->end();
			}
			const_iterator find(const value_type& val) const{
				const_node_ptr found = this->_root();
				while (found != nullptr) {
					if (this->_comp(val, found->_value))
						found = found->_left;
					else if (this->_comp(found->_value, val))
						found = found->_right;
					else
						return const_iterator(found);
				}
				return this->end();
			}
			size_type count(const value_type& val) const {
				return this->find(val) == this->end() ? 0 : 1;
			}
			
			//Finding the first element in the tree that is not less than the given value.
			iterator lower_bound(const value_type& val) {
				node_ptr found = this->_root();
				node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (!this->_comp(found->_value, val)) {
						parent = found;
						found = found->_left;
					}
					else
						found = found->_right;
				}
				return iterator(parent);
			}
			const_iterator lower_bound(const value_type& val) const {
				const_node_ptr found = this->_root();
				const_node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (!this->_comp(found->_value, val)) {
						parent = found;
						found = found->_left;
					}
					else
						found = found->_right;
				}
				return const_iterator(parent);
			}
			
			//Finding the first node that is greater than the value.
			iterator upper_bound(const value_type& val) {
				node_ptr found = this->_root();
				node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (this->_comp(val, found->_value)) {
						parent = found;
						found = found->_left;
					}
					else
						found = found->_right;
				}
				return iterator(parent);
			}
			const_iterator upper_bound(const value_type& val) const {
				const_node_ptr found = this->_root();
				const_node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (this->_comp(val, found->_value)) {
						parent = found;
						found = found->_left;
					}
					else
						found = found->_right;
				}
				return const_iterator(parent);
			}
			
			//Finding the range of values that are equal to the value passed in.
			ft::pair<iterator, iterator> equal_range(const value_type& val) {
				node_ptr found = this->_root();
				node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (this->_comp(val, found->_value)) {
						parent = found;
						found = found->_left;
					}
					else if (this->_comp(found->_value, val))
						found = found->_right;
					else
						return ft::make_pair(iterator(found), iterator(found->_right == nullptr ? parent : tree_min<value_type>(found->_right)));
				}
				return ft::make_pair(iterator(parent), iterator(parent));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const value_type& val) const {
				const_node_ptr found = this->_root();
				const_node_ptr parent = this->_end_tree();
				while (found != nullptr) {
					if (this->_comp(val, found->_value)) {
						parent = found;
						found = found->_left;
					}
					else if (this->_comp(found->_value, val))
						found = found->_right;
					else
						return ft::make_pair(const_iterator(found), const_iterator(found->_right == nullptr ? parent : tree_min<value_type>(found->_right)));
				}
				return ft::make_pair(const_iterator(parent), const_iterator(parent));
			}
		//Allocator
			allocator_type get_allocator() const { return this->_alloc; }
		
		private:
			//A function that returns the root node of the tree.
			node_ptr& _root() { return this->_parent._left; }
			
			//A const version of the _root() function.
			const_node_ptr& _root() const { return const_cast<const_node_ptr&>(this->_parent._left); }
			
			//Returning the address of the parent node.
			node_ptr _end_tree() { return &this->_parent; }
			const_node_ptr _end_tree() const { return const_cast<const_node_ptr>(&this->_parent);}
			
			//Getting the sibling of a node.
			node_ptr _get_sibling(node_ptr node) const {
				if (is_left_child<value_type>(node))
					return node->_parent->_right;
				else
					return node->_parent->_left;
			}
			
			//A helper function that returns the color of a node.
			Color _get_color(node_ptr node) const {
				if (node == nullptr)
					return black;
				return node->_color;
			}
			
			//Rotating the node to the left.
			void _rota_left(node_ptr node) {
				node_ptr right = node->_right;
				node->_right = right->_left;
				if (node->_right != nullptr)
					node->_right->_parent = node;
				right->_parent = node->_parent;
				if (is_left_child<value_type>(node))
					node->_parent->_left = right;
				else
					node->_parent->_right = right;
				right->_left = node;
				node->_parent = right;
			}
			
			//Rotating the node to the right.
			void _rota_right(node_ptr node) {
				node_ptr left = node->_left;
				node->_left = left->_right;
				if (node->_left != nullptr)
					node->_left->_parent = node;
				left->_parent = node->_parent;
				if (is_left_child<value_type>(node))
					node->_parent->_left = left;
				else
					node->_parent->_right = left;
				left->_right = node;
				node->_parent = left;
			}

			node_ptr _new_node(const value_type& val) {
				node_ptr node = this->_node_alloc.allocate(1);
				this->_alloc.construct(&node->_value, val);
				node->_color = red;
				node->_parent = node->_left = node->_right = nullptr;
				if (this->empty() || this->_comp(val, this->_begin->_value))
					this->_begin = node;
				++this->_size;
				return node;
			}

			node_ptr _insert_node(node_ptr node, node_ptr new_node, bool& done, iterator& pos) {
				if (node == nullptr) {
					done = true;
					pos = new_node;
					return new_node;
				}
				if (this->_comp(node->_value, new_node->_value)) {
					node->_right = _insert_node(node->_right, new_node, done, pos);
					node->_right->_parent = node;
				}
				else if (this->_comp(new_node->_value, node->_value)) {
					node->_left = _insert_node(node->_left, new_node, done, pos);
					node->_left->_parent = node;
				}
				else {
					pos = node;
					done = false;
				}
				return node;
			}

			node_ptr _copy_node(const_node_ptr node) {
				if (node == nullptr)
					return nullptr;
				node_ptr new_node = this->_new_node(node->_value);
				new_node->_left = _copy_node(node->_left);
				if (new_node->_left != nullptr)
					new_node->_left->_parent = new_node;
				new_node->_right = _copy_node(node->_right);
				if (new_node->_right != nullptr)
					new_node->_right->_parent = new_node;
				return new_node;
			}
			
			//Balancing the tree after an insertion.
			void _balance_insert(node_ptr node) {
				while (node != this->_root() && node->_parent->_color == red) {
					node_ptr uncle = this->_get_sibling(node->_parent);
					if (this->_get_color(uncle) == red) {
						uncle->color_swap();
						node = node->_parent;
						node->color_swap();
						node = node->_parent;
						node->color_swap();
					}
					else if (is_left_child<value_type>(node->_parent)) {
						if (!is_left_child<value_type>(node)) {
							node = node->_parent;
							this->_rota_left(node);
						}
						node = node->_parent;
						node->color_swap();
						node = node->_parent;
						node->color_swap();
						this->_rota_right(node);
						break;
					}
					else {
						if (is_left_child<value_type>(node)) {
							node = node->_parent;
							this->_rota_right(node);
						}
						node = node->_parent;
						node->color_swap();
						node = node->_parent;
						node->color_swap();
						this->_rota_left(node);
						break;
					}
				}
			}

			void _delete_node(node_ptr node) {
				if (node == nullptr)
					return;
				this->_alloc.destroy(&node->_value);
				this->_node_alloc.deallocate(node, 1);
				--this->_size;
			}
			
			void _erase(node_ptr root, node_ptr node) {
				node_ptr replacement = this->_replacement_node(node);
				node_ptr replacement_child = replacement->_left == nullptr ? replacement->_right : replacement->_left;
				node_ptr sibling = nullptr;
				if (replacement_child != nullptr)
					replacement_child->_parent = replacement->_parent;
				if (is_left_child<value_type>(replacement)) {
					replacement->_parent->_left = replacement_child;
					if (replacement == root)
						root = replacement_child;
					else
						sibling = replacement->_parent->_right;
				}
				else {
					replacement->_parent->_right = replacement_child;
					sibling = replacement->_parent->_left;
				}
				Color replacement_color = replacement->_color;
				if (replacement != node) {
					replacement->_parent = node->_parent;
					if (is_left_child<value_type>(node))
						node->_parent->_left = replacement;
					else
						node->_parent->_right = replacement;
					replacement->_left = node->_left;
					replacement->_left->_parent = replacement;
					replacement->_right = node->_right;
					if (replacement->_right != nullptr)
						replacement->_right->_parent = replacement;
					replacement->_color = node->_color;
					if (node == root)
						root = replacement;
				}
				if (replacement_color == black && root != nullptr) {
					if (replacement_child != nullptr)
						replacement_child->_color = black;
					else 
						this->_balance_erase(root, replacement_child, sibling);
				}
			}

			void _balance_erase(node_ptr root, node_ptr node, node_ptr sibling) {
				while (true) {
					if (!is_left_child<value_type>(sibling)) {
						if (this->_get_color(sibling) == red) {
							sibling->color_swap();
							sibling->_parent->color_swap();
							this->_rota_left(sibling->_parent);
							if (root == sibling->_left)
								root = sibling;
							sibling = sibling->_left->_right;
						}
						if (this->_get_color(sibling->_left) == black && this->_get_color(sibling->_right) == black) {
							sibling->color_swap();
							node = sibling->_parent;
							if (node == root || this->_get_color(node) == red) {
								node->_color = black;
								break;
							}
							sibling = this->_get_sibling(node);
						}
						else {
							if (this->_get_color(sibling->_right) == black) {
								sibling->_left->color_swap();
								sibling->color_swap();
								this->_rota_right(sibling);
								sibling = sibling->_parent;
							}
							sibling->_color = sibling->_parent->_color;
							sibling->_parent->_color = black;
							sibling->_right->_color = black;
							this->_rota_left(sibling->_parent);
							break;
						}
					}
					else {
						if (this->_get_color(sibling) == red) {
							sibling->color_swap();
							sibling->_parent->color_swap();
							this->_rota_right(sibling->_parent);
							if (root == sibling->_right)
								root = sibling;
							sibling = sibling->_right->_left;
						}
						if (this->_get_color(sibling->_right) == black && this->_get_color(sibling->_left) == black) {
							sibling->color_swap();
							node = sibling->_parent;
							if (node == root || this->_get_color(node) == red) {
								node->_color = black;
								break;
							}
							sibling = this->_get_sibling(node);
						}
						else {
							if (this->_get_color(sibling->_left) == black) {
								sibling->_right->color_swap();
								sibling->color_swap();
								this->_rota_left(sibling);
								sibling = sibling->_parent;
							}
							sibling->_color = sibling->_parent->_color;
							sibling->_parent->_color = black;
							sibling->_left->_color = black;
							this->_rota_right(sibling->_parent);
							break;
						}
					}
				}
			}
			void _clear(node_ptr node) {
				if (node == nullptr)
					return;
				_clear(node->_left);
				_clear(node->_right);
				this->_delete_node(node);
			}
			node_ptr _replacement_node(node_ptr node) const	{
				if (node->_left == nullptr || node->_right == nullptr)
					return node;
				else
					return tree_min<value_type>(node->_right);
			}
	};
	template <typename T, typename Compare, typename Alloc>
	void swap(RedBlackTree<T, Compare, Alloc>& lhs, RedBlackTree<T, Compare, Alloc>& rhs) {
			lhs.swap(rhs);
		}
}

#endif /* REDBLACKTREE_HPP */
