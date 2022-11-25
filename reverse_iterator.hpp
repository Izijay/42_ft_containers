/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:16:40 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 13:55:22 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <cstddef>
namespace ft {
	template<class iterator>
		class reverse_iterator {

		public:
			typedef iterator iterator_type;
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::value_type 			value_type;
			typedef typename iterator::difference_type 		difference_type;
			typedef typename iterator::pointer 				pointer;
			typedef typename iterator::reference			reference;
		
		private :
			iterator _current;

		public :
			reverse_iterator() : _current(NULL) {}
			explicit reverse_iterator(iterator_type x) { _current = x; }
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& u) : _current(u.base()) {}

			iterator_type base() const { return _current; }

			reference operator*() const {
				iterator_type tmp = _current;
				return (*(--tmp));
			}
			pointer operator->() const {
				return &(operator*());
			}
			reverse_iterator& operator++() {
				--_current;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				--_current;
				return tmp;
			}
			reverse_iterator& operator--() {
				++_current;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			}
			reverse_iterator operator+(difference_type n) const {
				return reverse_iterator(_current - n);
			}
			template <class U>
			difference_type operator-(const reverse_iterator<U>& u) const {
				return u.base() - _current;
			}
			reverse_iterator operator-(difference_type n) const {
				return reverse_iterator(this->_current.operator+(n));
			}
			reverse_iterator& operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			reverse_iterator& operator-=(difference_type n) {
				_current += n;
				return *this;
			}
			reference operator[](difference_type n) const {
				return *(*this + n);
			}
			friend reverse_iterator operator+(difference_type n, const reverse_iterator& it) {
				return reverse_iterator(it._current - n);
			}
		};

	template<class ite, class ite2>
	bool operator==(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() == rhs.base();
	}
	template<class ite, class ite2>
	bool operator!=(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() != rhs.base();
	}
	template<class ite, class ite2>
	bool operator<(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() > rhs.base();
	}
	template<class ite, class ite2>
	bool operator>(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() < rhs.base();
	}
	template<class ite, class ite2>
	bool operator<=(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template<class ite, class ite2>
	bool operator>=(const reverse_iterator<ite>& lhs, const reverse_iterator<ite2>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template<class ite>
	reverse_iterator<ite> operator+(typename reverse_iterator<ite>::difference_type n, const reverse_iterator<ite>& rhs) {
		return reverse_iterator<ite>(rhs.base() - n);
	}
}

#endif /* REVERSE_ITERATOR_HPP */