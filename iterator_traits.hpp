/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:48:24 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 10:36:18 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>
namespace ft {

	struct input_iterator_tag {
	};
	struct output_iterator_tag {
	};
	struct forward_iterator_tag : public input_iterator_tag {
	};
	struct bidirectional_iterator_tag : public forward_iterator_tag {
	};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {
	};

	template<typename T>
	struct iterator_traits {
		typedef std::ptrdiff_t 				difference_type;
		typedef T 							value_type;
		typedef T 							*pointer;
		typedef T 							&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename T>
	struct iterator_traits<const T> {
		typedef std::ptrdiff_t 				difference_type;
		typedef T 							value_type;
		typedef const T 					*pointer;
		typedef const T 					&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename T>
	struct iterator_traits<T *> {
		typedef std::ptrdiff_t 				difference_type;
		typedef T 							value_type;
		typedef T 							*pointer;
		typedef T 							&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename T>
	struct iterator_traits<const T *> {
		typedef std::ptrdiff_t 				difference_type;
		typedef T 							value_type;
		typedef const T 					*pointer;
		typedef const T 					&reference;
		typedef random_access_iterator_tag	iterator_category;
	};
}

#endif 		// ITERATOR_TRAITS_HPP