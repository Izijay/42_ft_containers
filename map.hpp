/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:31:21 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 15:33:50 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "RedBlackTree.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <cstddef>

#ifndef nullptr
# define nullptr NULL
#endif
namespace ft {
	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
	public:
		typedef T 													mapped_type;
		typedef Key 												key_type;
		typedef Compare 											key_compare;
		typedef Allocator 											allocator_type;
		typedef ft::pair<const key_type, mapped_type> 				value_type;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type 			difference_type;
		typedef typename allocator_type::reference 					reference;
		typedef typename allocator_type::const_reference 			const_reference;
		typedef typename allocator_type::pointer 					pointer;
		typedef typename allocator_type::const_pointer			 	const_pointer;

		class value_compare : public ft::binary_function<value_type, value_type, bool> {
			friend class map;
			protected:
			key_compare _comp;
			value_compare(key_compare comp) : _comp(comp) {}
			public:
			bool operator()(const value_type& x, const value_type& y) const {
				return _comp(x.first, y.first);
			}
		};

		private:
			typedef ft::RedBlackTree<value_type, value_compare, allocator_type>	tree_type;
		public:
			typedef typename tree_type::iterator					iterator;
			typedef typename tree_type::const_iterator				const_iterator;
			typedef typename tree_type::reverse_iterator			reverse_iterator;
			typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;

		protected:
			tree_type												_tree;

		public:
		// Constructors
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc) {};
			template <typename InputIterator>
				map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(value_compare(comp), alloc) {
					this->insert(first, last);
				}
			map(const map& other) : _tree(other._tree) {};
		// Destructor
			~map() {}
		// operator = and []
			map& operator=(const map& other) {
				if (this != &other)
					this->_tree = other._tree;
				return *this;
			}
			mapped_type& operator[](const key_type& key) {
				iterator it(this->insert(ft::make_pair(key, mapped_type())).first);
				return (*it).second;
			}
			mapped_type& at(const key_type& key) {
				iterator it(this->find(key));
				if (it == this->end())
					throw std::out_of_range("map::at");
				return (*it).second;
			}
			const mapped_type& at(const key_type& key) const {
				const_iterator it(this->find(key));
				if (it == this->end())
					throw std::out_of_range("map::at");
				return (*it).second;
			}
		// Iterators
			iterator begin() { return this->_tree.begin(); }
			const_iterator begin() const { return this->_tree.begin(); }
			iterator end() { return this->_tree.end(); }
			const_iterator end() const { return this->_tree.end(); }
			reverse_iterator rbegin() { return this->_tree.rbegin(); }
			const_reverse_iterator rbegin() const { return this->_tree.rbegin(); }
			reverse_iterator rend() { return this->_tree.rend(); }
			const_reverse_iterator rend() const { return this->_tree.rend(); }
		// Capacity
			bool empty() const { return this->_tree.empty(); }
			size_type size() const { return this->_tree.size(); }
			size_type max_size() const { return this->_tree.max_size(); }
		// Modifiers
			ft::pair<iterator, bool> insert(const value_type& val) { return this->_tree.insert(val); }
			iterator insert(iterator position, const value_type& val) { return this->_tree.insert(position, val); }
			template <typename InputIterator>
				void insert(InputIterator first, InputIterator last) { this->_tree.insert(first, last); }
			void erase(iterator pos) { return this->_tree.erase(pos); }
			void erase(iterator first, iterator last) { return this->_tree.erase(first, last); }
			size_type erase(const key_type& key) { return this->_tree.erase(ft::make_pair(key, mapped_type())); }
			void clear() { this->_tree.clear(); }
			void swap(map& other) { this->_tree.swap(other._tree); }
		// Observers
			key_compare key_comp() const { return key_compare(); }
			value_compare value_comp() const { return this->_tree.value_cmp(); }
		// Lookup
			iterator find(const key_type& key) { return this->_tree.find(ft::make_pair(key, mapped_type())); }
			const_iterator find(const key_type& key) const { return this->_tree.find(ft::make_pair(key, mapped_type())); }
			size_type count(const key_type& key) const { return this->_tree.count(ft::make_pair(key, mapped_type())); }
			iterator lower_bound(const key_type& key) { return this->_tree.lower_bound(ft::make_pair(key, mapped_type())); }
			const_iterator lower_bound(const key_type& key) const { return this->_tree.lower_bound(ft::make_pair(key, mapped_type())); }
			iterator upper_bound(const key_type& key) { return this->_tree.upper_bound(ft::make_pair(key, mapped_type())); }
			const_iterator upper_bound(const key_type& key) const { return this->_tree.upper_bound(ft::make_pair(key, mapped_type())); }
			ft::pair<iterator, iterator> equal_range(const key_type& key) { return this->_tree.equal_range(ft::make_pair(key, mapped_type())); }
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const { return this->_tree.equal_range(ft::make_pair(key, mapped_type())); }
		// Allocator
			allocator_type get_allocator() const { return this->_tree.get_allocator(); }
	};
	// Non-member functions
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator==(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator!=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return !(lhs == rhs);
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator<(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator>(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return rhs < lhs;
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator<=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return !(rhs < lhs);
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		bool operator>=(const map<Key, T, Compare, Allocator>& lhs, const map<Key, T, Compare, Allocator>& rhs) {
			return !(lhs < rhs);
		}
	template <typename Key, typename T, typename Compare, typename Allocator>
		void swap(map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs) {
			lhs.swap(rhs);
		}
}

#endif // MAP_HPP