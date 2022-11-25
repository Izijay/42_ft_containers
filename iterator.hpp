/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:29:08 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 12:04:27 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <cstddef> //ptrdiff_t
#include "iterator_traits.hpp"
namespace ft {
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
		public:
			typedef T 									value_type;
			typedef Category 							iterator_category;
			typedef Distance 							difference_type;
			typedef T* 									pointer;
			typedef T& 									reference;
		
		private:
			pointer											_ptr;
		
		public:
			iterator() : _ptr(NULL) {}
			iterator(pointer ptr) : _ptr(ptr) {}
			iterator(const iterator& it) : _ptr(it._ptr) {}
			iterator& operator=(const iterator& it) {
				_ptr = it._ptr;
				return *this;
			}
			reference operator*() { return *_ptr; }
			pointer operator->() const { return _ptr; }
			iterator& operator++() {
				++_ptr;
				return *this;
			}
			iterator operator++(int) {
				iterator tmp(*this);
				++_ptr;
				return tmp;
			}
			iterator& operator--() {
				--_ptr;
				return *this;
			}
			iterator operator--(int) {
				iterator tmp(*this);
				--_ptr;
				return tmp;
			}
			iterator& operator+=(difference_type n) {
				_ptr += n;
				return *this;
			}
			iterator& operator-=(difference_type n) {
				_ptr -= n;
				return *this;
			}
			iterator operator+(difference_type n) const {
				return iterator(_ptr + n);
			}
			iterator operator-(difference_type n) const {
				iterator tmp(*this);
				tmp._ptr -= n;
				return tmp;
			}
			difference_type operator-(const iterator& it) const {
				return base() - it.base();
			}
			template <class U>
			difference_type operator-(U& it) const {
				return base() - it.base();
			}
			reference operator[](difference_type n) {
				return _ptr[n];
			}
			pointer base() const { return _ptr; }
			
			template <class U>
			bool operator==(const U& lhs) const {
				return (_ptr == lhs.base());
			}
			template <class U>
			bool operator!=(const U& lhs) const {
				return _ptr != lhs.base();
			}
			template <class U>
			bool operator<(const U& lhs) const {
				return _ptr < lhs.base();
			}
			template <class U>
			bool operator>(const U& lhs) const {
				return _ptr > lhs.base();
			}
			template <class U>
			bool operator<=(const U& lhs) const {
				return _ptr <= lhs.base();
			}
			template <class U>
			bool operator>=(const U& lhs) const {
				return _ptr >= lhs.base();
			}

			operator iterator<ft::random_access_iterator_tag, const value_type>() const {
				return iterator<ft::random_access_iterator_tag, const value_type>(_ptr);
			}
			
			friend iterator operator+(difference_type n, const iterator& it) {
				return iterator(it._ptr + n);
			}
	};
}

#endif /* ITERATOR_HPP */