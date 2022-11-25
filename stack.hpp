/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:49:19 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 15:41:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

	template<class T, class Container = vector<T> >
	class stack {
		public:
			typedef Container 									container_type;
			typedef typename container_type::value_type 		value_type;
			typedef typename container_type::size_type 			size_type;
			typedef typename container_type::reference 			reference;
			typedef typename container_type::const_reference	const_reference;

		protected:
			container_type _c;

		public:
			explicit stack(const container_type &c = container_type()) : _c(c) {}
			stack &operator=(const stack &x) {
				_c = x._c;
				return *this;
			}
			virtual ~stack() {}

			bool empty() const { return _c.empty(); }
			size_type size() const { return _c.size(); }
			value_type &top() { return _c.back(); }
			const value_type &top() const { return _c.back(); }
			void push(const value_type &x) { _c.push_back(x); }
			void pop() { _c.pop_back(); }

			template <class T1, class C1>
			friend bool operator==(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);

			template <class T1, class C1>
			friend bool operator<(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);
	};

	template<class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return lhs._c == rhs._c;
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return lhs._c < rhs._c;
	}

	template<class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return rhs < lhs;
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return !(lhs < rhs);
	}
}

#endif //STACK_HPP
