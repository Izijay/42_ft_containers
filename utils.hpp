/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:01:38 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 15:30:38 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

//It's a copy function that copies the elements from the range [first, last] into the range beginning at result.
namespace ft {

// swap function that swaps the values of first and second.
	template<typename T>
	void swap(T& first, T& second)
	{
		T temp = first;
		first = second;
		second = temp;
	}
//equal / compare functions ---------------------------------------------------
	template <class InputIte1, class InputIte2>
	bool equal(InputIte1 first1, InputIte1 last1, InputIte2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIte1, class InputIte2, class BinaryPredicate>
	bool equal(InputIte1 first1, InputIte1 last1, InputIte2 first2, BinaryPredicate p) {
		while (first1 != last1) {
			if (!p(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIte1, class InputIte2>
	bool lexicographical_compare(InputIte1 first1, InputIte1 last1, InputIte2 first2, InputIte2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIte1, class InputIte2, class Compare>
	bool lexicographical_compare(InputIte1 first1, InputIte1 last1, InputIte2 first2, InputIte2 last2, Compare comp) {
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return first2 != last2;
	}
// PAIR --------------------------------------------------------------
	template <typename T1, typename T2>
	struct pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		public:
			pair();
			pair(const first_type& x, const second_type& y);
			template <typename U, typename V>
				pair(const pair<U, V>& p);
			pair& operator=(const pair& p);
		public:
			T1 first;
			T2 second;
	};

	template <typename T1, typename T2>
	pair<T1, T2>::pair() : first(), second() {}
	template <typename T1, typename T2>
	pair<T1, T2>::pair(const first_type& x, const second_type& y) : first(x), second(y) {}
	template <typename T1, typename T2>
	template <typename U, typename V>
	pair<T1, T2>::pair(const pair<U, V>& p) : first(p.first), second(p.second) {}
	template <typename T1, typename T2>
	pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1,T2>& p) {
		if (this != &p) {
			first = p.first;
			second = p.second;
		}
		return *this;
	}
	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return p1.first == p2.first && p1.second == p2.second;
	}
	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p1 == p2);
	}
	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return p1.first < p2.first || (!(p2.first < p1.first) && p1.second < p2.second);
	}
	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return p2 < p1;
	}
	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p2 < p1);
	}
	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2>& p1, const pair<T1, T2>& p2) {
		return !(p1 < p2);
	}

	template <typename T1, typename T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y) {
		return ft::pair<T1, T2>(x, y);
	}


// is_integral / enable_if
	template <class T>
	struct is_integral {
		static const bool value = false;
	};
	template <>
	struct is_integral<bool> {
		static const bool value = true;
	};
	template <>
	struct is_integral<char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<signed char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};
	template <>
	struct is_integral<short int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long long int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long long int> {
		static const bool value = true;
	};
	
	template <bool Cond, class T = void>
	struct enable_if {};
	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// binary_function
	template <typename T1, typename T2, typename Res>
	struct binary_function {
		typedef T1 first_argument_type;
		typedef T2 second_argument_type;
		typedef Res result_type;
	};
	template <typename T>
	struct less: binary_function<T, T, bool> {
		bool operator()(const T& x, const T& y) const {
			return x < y;
		}
	};
}

#endif // UTILS_HPP