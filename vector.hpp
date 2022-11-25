/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:21:22 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 13:34:19 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include "iterator_traits.hpp"
# include <iostream>

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::iterator<random_access_iterator_tag, value_type> 		iterator;
			typedef ft::iterator<random_access_iterator_tag, const value_type> 	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		private:
			pointer 		_start;
			pointer 		_finish;
			pointer 		_end_of_storage;
			allocator_type 	_alloc;

		public:
		// Constructors
			explicit vector(const allocator_type& alloc = allocator_type()) : _start(NULL), _finish(NULL), _end_of_storage(NULL), _alloc(alloc){}
			
			explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				_start = _alloc.allocate(n);
				_finish = _start;
				_end_of_storage = _start + n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_finish++, value);
			}
					
			template<class InputIterator>
			vector(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator(), 
					const allocator_type &alloc = allocator_type()) : _start(NULL), _finish(NULL), _end_of_storage(NULL), _alloc(alloc) {
				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;
				_start = _alloc.allocate(n);
				_finish = _start;
				_end_of_storage = _start + (n);
				for (; first != last; ++first)
					_alloc.construct(_finish++, *first);
			}
			// - Copy constructor
			vector(const vector& other) : _start(NULL), _finish(NULL), _end_of_storage(NULL), _alloc(other._alloc) {
				*this = other;
			}
		
		// Destructor
			~vector() {
				if (_start) {
					for (pointer p = _start; p != _finish; ++p)
						_alloc.destroy(p);
					_alloc.deallocate(_start, size());
				}
			}
		
		// Assignation
			vector& operator=(const vector& other) {
				if (*this != other && _finish != other._finish) {
					clear();
					this->assign(other.begin(), other.end());
				}
				return *this;
			}
		
		// Iterators
			iterator begin()   { return iterator(_start); }
			iterator end()   { return iterator(_finish); }
			const_iterator begin() const   { return const_iterator(_start); }
			const_iterator end() const   { return const_iterator(_finish); }

		// Reverse iterators
			reverse_iterator rbegin()   { return reverse_iterator(end()); }
			reverse_iterator rend()   { return reverse_iterator(begin()); }
			const_reverse_iterator rbegin() const   { return const_reverse_iterator(end()); }
			const_reverse_iterator rend() const   { return const_reverse_iterator(begin()); }
		
		// Element access
			reference operator[](size_type n) { return _start[n]; }
			const_reference operator[](size_type n) const { return _start[n]; }
			reference at(size_type n) {
				if (n >= size())
					throw std::out_of_range("vector::at() out of range");
				return _start[n];
			}
			const_reference at(size_type n) const {
				if (n >= size())
					throw std::out_of_range("vector::at() out of range");
				return _start[n];
			}
			reference front() { return _start[0]; }
			const_reference front() const { return _start[0]; }
			reference back() { return _finish[-1]; }
			const_reference back() const { return _finish[-1]; }
			pointer data()   { return _start; }
			const_pointer data() const   { return _start; }
		
		// Capacity
			size_type size() const   { return _finish - _start; }
			void resize(size_type n, value_type value = value_type()) {
				size_type old_size = size();
				if (old_size >= n)
					this->erase(begin() + n, end());
				else {
					this->reserve(n);
					for (; old_size < n; ++old_size)
						this->push_back(value);
				}
			}

			size_type max_size() const   { return allocator_type().max_size(); }
			size_type capacity() const   { return _end_of_storage - _start; }
			bool empty() const   { return _start == _finish; }

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last) {
				this->clear();
				this->insert(this->begin(), first, last);
			}
			
			void assign(size_type n, const value_type& value) {
				this->clear();
				if (n == 0)
					return;
				if (size_type(_end_of_storage - _start) >= n) {
					while (n) {
						_alloc.construct(_finish++, value);
						n--;
					}
				}
				else {
					_alloc.deallocate(_start, capacity());
					_start = _alloc.allocate(n);
					_finish = _start;
					_end_of_storage = _start + n;
					while (n) {
						_alloc.construct(_finish++, value);
						n--;
					}
				}
			}
			
			void reserve(size_type n) {		
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (n == 0)
					return ;			
				else if (n > this->capacity())
				{
					pointer prev_start = _start;
					pointer tmp = _start;
					pointer prev_end = _finish;
					size_type prev_size = this->size();
					size_type prev_capacity = this->capacity();
					
					_start = _alloc.allocate( n );
					_end_of_storage = _start + n;
					_finish = _start;
					while (prev_start != prev_end)
					{
						_alloc.construct(_finish, *prev_start);
						_finish++;
						prev_start++;
					}
					for (pointer p = tmp; p != prev_end; p++)
						_alloc.destroy(p);
					_alloc.deallocate(prev_start - prev_size, prev_capacity);
				}
			}
			
		// Modifiers
			void push_back(const value_type& value) {
				if (this->size() == this->capacity()) 
					reserve(size() == 0 ? 1 : size() * 2);
				this->_alloc.construct(this->_finish, value);
				++this->_finish;
			}
			void pop_back() {
				if (_finish != _start) {
					--_finish;
					_alloc.destroy(_finish);
				}
			}

			iterator insert(iterator position, const value_type& value) {
				difference_type index = position - this->begin();
				this->insert(position, 1, value);
				return iterator(this->begin() + index);
			}
			
			void insert(iterator position, size_type n, const value_type& value) {
				difference_type const index = position - this->begin();
				difference_type const old_finish_index = this->end() - this->begin();
				iterator old_finish, finish;
				this->resize(this->size() + n);
				finish = this->end();
				position = this->begin() + index;
				old_finish = this->begin() + old_finish_index;
				while (old_finish != position)
					*--finish = *--old_finish;
				while (n-- > 0)
					*position++ = value;
			}
			
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) {
				if (first == last)
					return;
				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;
				size_type dist = position - this->begin();
				size_type old_size = this->size();
				this->resize(old_size + n);
				position = this->begin() + dist;
				for (size_type i = old_size + n - 1; i >= dist + n; i--)
					this->_start[i] = this->_start[i - n];
				for (size_type i = 0; i < n; i++)
					this->_start[dist + i] = *first++;
			}

			iterator erase(iterator position) {
				pointer p = &(*position);
				_alloc.destroy(p);
				if (p + 1 == _finish)
					_alloc.destroy(p);
				else {
					for (int i = 0; i < _finish - p - 1; i++) {
						_alloc.construct(p + i, *(p + i + 1));
						_alloc.destroy(p + i + 1);
					}
				}
				_finish -= 1;
				return iterator(p);
			}
			
			iterator erase(iterator first, iterator last) {
				pointer p = &(*first);
				for (; first != last; first++)
					_alloc.destroy(&(*first));
				for (int i = 0; i < _finish - &(*last); i++) {
					_alloc.construct(p + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_finish -= (&(*last) - p);
				return iterator(p);
			}

			void clear() {
				for (pointer p = _start; p != _finish; ++p)
					_alloc.destroy(p);
				_finish = _start;
			}

			void swap(vector& x) {
				ft::swap(_start, x._start);
				ft::swap(_finish, x._finish);
				ft::swap(_end_of_storage, x._end_of_storage);
			}

			allocator_type get_allocator() const {
				return _alloc;
			}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		if (x.size() != y.size())
			return false;
		typename vector<T, Alloc>::const_iterator px = x.begin();
		typename vector<T, Alloc>::const_iterator py = y.begin();
		while (px != x.end()) {
			if (*px != *py)
				return false;
			++px;
			++py;
		}
		return true;
	}
	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		return !(x == y);
	}
	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}
	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		return y < x;
	}
	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		return !(y < x);
	}
	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& x, const vector<T, Alloc>& y) {
		return !(x < y);
	}
	template<class T, class Alloc>	
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
		x.swap(y);
	}
}

#endif
