/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:07:38 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 10:51:11 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include "../vector.hpp"
#define COMPARE(x) ((x) ? (std::cout << "\033[1;32mOK\033[0m\n") : (std::cout << "\033[1;31mKO\033[0m\n"))

inline void ft_iterators(void) {
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<< ITERATOR VECTOR TEST >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::vector<int> v_std(3, 4);
	std::vector<int>::iterator it_std = v_std.begin();
	std::vector<int>::iterator ite_std = v_std.begin() + 1;

	ft::vector<int> v(3, 4);
	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator ite = v.begin() + 1;
	ft::vector<int>::iterator tmp;

	std::cout << "Copy Constructor :\t\t\t";
	{
		ft::vector<int>::iterator it2(it);
		COMPARE(&(*it) == &(*it2));
	}
	std::cout << "Iterator to Const Iterator:\t\t";
	{
		ft::vector<int>::const_iterator const_it, const_ite(it);
		const_it = it;
		COMPARE(&(*it) == &(*const_it) && &(*it) == &(*const_ite));
	}
	std::cout << "\t-- Operators overload --" << std::endl;
	std::cout << "Operator == :\t\t\t\t";
	COMPARE((it == ite) == (it_std == ite_std));
	std::cout << "Operator != :\t\t\t\t";
	COMPARE((it != ite) == (it_std != ite_std));
	std::cout << "Operator < :\t\t\t\t";
	COMPARE((it < ite) == (it_std < ite_std));
	std::cout << "Operator > :\t\t\t\t";
	COMPARE((it > ite) == (it_std > ite_std));
	std::cout << "Operator <= :\t\t\t\t";
	COMPARE((it <= ite) == (it_std <= ite_std));
	std::cout << "Operator >= :\t\t\t\t";
	COMPARE((it >= ite) == (it_std >= ite_std));
	std::cout << "Operator * :\t\t\t\t";
	COMPARE(((*it = 6) == 6) && (*it == *(v.begin())));
	std::cout << "Operator -> :\t\t\t\t";
	{
		std::vector<std::string> v_std(3, "test");
		std::vector<std::string>::iterator it_std = v_std.begin();
		ft::vector<std::string> v(3, "test");
		ft::vector<std::string>::iterator it = v.begin();
		COMPARE(it->length() == it_std->length());
	}
	std::cout << "Operator ++it :\t\t\t\t";
	++it;
	COMPARE(&(*it) == &(*ite));
	std::cout << "Operator --it :\t\t\t\t";
	--it;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator it++ :\t\t\t\t";
	tmp = it++;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*ite)));
	std::cout << "Operator it-- :\t\t\t\t";
	tmp = it--;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*(v.begin()))));
	std::cout << "Operator += :\t\t\t\t";
	it += 1;
	COMPARE(&(*it) == &(*(ite)));
	std::cout << "Operator -= :\t\t\t\t";
	it -= 1;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator [] :\t\t\t\t";
	COMPARE((it[1] == v[1]) && (it[1] == v_std[1]));
	std::cout << "Operator - :\t\t\t\t";
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator + (int) :\t\t\t";
	COMPARE(&(*(1 + it)) == &(*(ite)) && (&(*it) == &(*(v.begin()))));
	std::cout << "Operator - (int) :\t\t\t";
	COMPARE((ite - it == 1) && (it - ite == -1));
}

inline void ft_const_iterators(void)
{
	std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<< CONST ITERATOR VECTOR TEST >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::vector<int> v_std(3, 4);
	std::vector<int>::const_iterator it_std = v_std.begin();
	std::vector<int>::const_iterator ite_std = v_std.begin() + 1;
	ft::vector<int> v(3, 4);
	ft::vector<int>::const_iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.begin() + 1;
	ft::vector<int>::const_iterator tmp;
	std::cout << "Copy Constructor :\t\t\t";
	{
		ft::vector<int>::const_iterator it2(it);
		COMPARE(&(*it) == &(*it2));
	}
	std::cout << "\t-- Operators overload --" << std::endl;
	std::cout << "Operator == :\t\t\t\t";
	COMPARE((it == ite) == (it_std == ite_std));
	std::cout << "Operator != :\t\t\t\t";
	COMPARE((it != ite) == (it_std != ite_std));
	std::cout << "Operator < :\t\t\t\t";
	COMPARE((it < ite) == (it_std < ite_std));
	std::cout << "Operator > :\t\t\t\t";
	COMPARE((it > ite) == (it_std > ite_std));
	std::cout << "Operator <= :\t\t\t\t";
	COMPARE((it <= ite) == (it_std <= ite_std));
	std::cout << "Operator >= :\t\t\t\t";
	COMPARE((it >= ite) == (it_std >= ite_std));
	std::cout << "Operator * :\t\t\t\t";
	COMPARE(*it == *(v.begin()) && (&(*it) == &(*(v.begin()))));
	std::cout << "Operator -> :\t\t\t\t";
	{
		std::vector<std::string> v_std(3, "test");
		std::vector<std::string>::const_iterator it_std = v_std.begin();
		ft::vector<std::string> v(3, "test");
		ft::vector<std::string>::const_iterator it = v.begin();
		COMPARE(it->length() == it_std->length());
	}
	std::cout << "Operator ++it :\t\t\t\t";
	++it;
	COMPARE(&(*it) == &(*ite));
	std::cout << "Operator --it :\t\t\t\t";
	--it;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator it++ :\t\t\t\t";
	tmp = it++;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*ite)));
	std::cout << "Operator it-- :\t\t\t\t";
	tmp = it--;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*(v.begin()))));
	std::cout << "Operator += :\t\t\t\t";
	it += 1;
	COMPARE(&(*it) == &(*(ite)));
	std::cout << "Operator -= :\t\t\t\t";
	it -= 1;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator [] :\t\t\t\t";
	COMPARE((it[1] == v[1]) && (it[1] == v_std[1]));
	std::cout << "Operator - :\t\t\t\t";
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator + (int) :\t\t\t";
	COMPARE(&(*(1 + it)) == &(*(ite)) && (&(*it) == &(*(v.begin()))));
	std::cout << "Operator - (int) :\t\t\t";
	COMPARE((ite - it == 1) && (it - ite == -1));
}

inline void	ft_reverse_iterators(void){
	std::cout << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<< REVERSE ITERATOR VECTOR TEST >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::vector<int> v_std(3, 4);
	std::vector<int>::reverse_iterator it_std = v_std.rbegin();
	std::vector<int>::reverse_iterator ite_std = v_std.rbegin() + 1;
	ft::vector<int> v(3, 4);
	ft::vector<int>::reverse_iterator it = v.rbegin();
	ft::vector<int>::reverse_iterator ite = v.rbegin() + 1;
	ft::vector<int>::reverse_iterator tmp;
	std::cout << "Copy Constructor :\t\t\t";
	{
		ft::vector<int>::reverse_iterator it2(it);
		COMPARE(&(*it) == &(*it2));
	}
	std::cout << "r_iterator to const_r_iterator:\t\t";
	{
		ft::vector<int>::const_reverse_iterator const_it, const_ite(it);
		const_it = it;
		COMPARE(&(*it) == &(*const_it) && &(*it) == &(*const_ite));
	}
	std::cout << "base() methode :\t\t\t";
	COMPARE(&(*it) == &(*(ite.base())) && (&(*it_std) == &(*(ite_std.base()))));
	std::cout << "\t-- Operators overload --" << std::endl;
	std::cout << "Operator == :\t\t\t\t";
	COMPARE((it == ite) == (it_std == ite_std));
	std::cout << "Operator != :\t\t\t\t";
	COMPARE((it != ite) == (it_std != ite_std));
	std::cout << "Operator < :\t\t\t\t";
	COMPARE((it < ite) == (it_std < ite_std));
	std::cout << "Operator > :\t\t\t\t";
	COMPARE((it > ite) == (it_std > ite_std));
	std::cout << "Operator <= :\t\t\t\t";
	COMPARE((it <= ite) == (it_std <= ite_std));
	std::cout << "Operator >= :\t\t\t\t";
	COMPARE((it >= ite) == (it_std >= ite_std));
	std::cout << "Operator * :\t\t\t\t";
	COMPARE(*it == *(v.rbegin()) && (&(*it) == &(*(v.rbegin()))));
	std::cout << "Operator -> :\t\t\t\t";
	{
		std::vector<std::string> v_std(3, "test");
		std::vector<std::string>::reverse_iterator it_std = v_std.rbegin();
		ft::vector<std::string> v(3, "test");
		ft::vector<std::string>::reverse_iterator it = v.rbegin();
		COMPARE(it->length() == it_std->length());
	}
	std::cout << "Operator ++it :\t\t\t\t";
	++it;
	COMPARE(&(*it) == &(*ite));
	std::cout << "Operator --it :\t\t\t\t";
	--it;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator it++ :\t\t\t\t";
	tmp = it++;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*ite)));
	std::cout << "Operator it-- :\t\t\t\t";
	tmp = it--;
	COMPARE(&(*it) != &(*tmp) && (&(*it) == &(*(v.rbegin()))));
	std::cout << "Operator += :\t\t\t\t";
	it += 1;
	COMPARE(&(*it) == &(*(ite)));
	std::cout << "Operator -= :\t\t\t\t";
	it -= 1;
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator [] :\t\t\t\t";
	COMPARE((it[1] == v[1]) && (it[1] == v_std[1]));
	std::cout << "Operator - :\t\t\t\t";
	COMPARE(&(*it) == &(*(ite - 1)));
	std::cout << "Operator + :\t\t\t\t";
	COMPARE((&(*(it + 1)) == &(*ite)) && (&(*(it_std + 1)) == &(*ite_std)));
	std::cout << "Operator + (int) :\t\t\t";
	COMPARE(&(*(1 + it)) == &(*(ite)) && (&(*it) == &(*(v.rbegin()))));
	std::cout << "Operator - (int) :\t\t\t";
	COMPARE((ite - it == 1) && (it - ite == -1));
}

#define T_SIZE_TYPE typename ft::vector<T>::size_type
template <typename T>
void printVector(int ok, ft::vector<T> &v, std::ostream &os, bool content = true){
	const T_SIZE_TYPE size = v.size();
	const T_SIZE_TYPE capacity = v.capacity();
	const std::string isOk = (capacity >= size) ? "OK" : "KO";
	os << "- size: " << size << std::endl;
	if (ok == 1)
		os << "- capacity: " << capacity << std::endl;
	os << "- max_size: " << v.max_size() << std::endl;
	if (content) {
		typename ft::vector<T>::const_iterator it = v.begin();
		typename ft::vector<T>::const_iterator ite = v.end();
		os << "- content: \n\t";
		for (; it != ite; ++it)
			os << *it << " ";
	}
	os << "\n<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>\n";
}
#define T_SIZE_TYPE2 typename std::vector<T>::size_type
template <typename T>
void printVectorStd(int ok, std::vector<T> &v, std::ostream &os, bool content = true){
	const T_SIZE_TYPE2 size = v.size();
	const T_SIZE_TYPE2 capacity = v.capacity();
	const std::string isOk = (capacity >= size) ? "OK" : "KO";
	os << "- size: " << size << std::endl;
	if (ok == 1)
		os << "- capacity: " << capacity << std::endl;
	os << "- max_size: " << v.max_size() << std::endl;
	if (content) {
		typename std::vector<T>::const_iterator it = v.begin();
		typename std::vector<T>::const_iterator ite = v.end();
		os << "- content: \n\t";
		for (; it != ite; ++it)
			os << *it << " ";
	}
	os << "\n<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>\n";
}

inline void ft_vector_tests(void){
	std::fstream file;
	std::fstream file_std;
	file.open("my_vector_test.txt", std::ios::out | std::ios::trunc);
	file_std.open("std_vector_test.txt", std::ios::out | std::ios::trunc);
	{
		file << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<< VECTOR TEST >>>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;
		file << "\t\t -- Constructors --\n";
		file << "-# Default : one (empty):" << std::endl;
		ft::vector<int> one;
		printVector(1, one, file);
		file << "-# Fill : two (size = 5, value = 42):" << std::endl;
		ft::vector<int> two(4, 42);
		printVector(1, two, file);
		file << "-# Range : three (from two.begin() to two.end() ):" << std::endl;
		ft::vector<int> three(two.begin(), two.end());
		printVector(1, three, file);
		file << "-# Copy : four (from three):" << std::endl;
		ft::vector<int> four(three);
		printVector(1, four, file);
		file << "-# Assignation : five (from four):" << std::endl;
		ft::vector<int> five;
		five = four;
		printVector(1, five, file);
	}
	{
		file_std << std::endl << "<<<<<<<<<<<<<<<<<<<<<<<<< VECTOR TEST >>>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;
		file_std << "\t\t -- Constructors --\n";
		file_std << "-# Default : one (empty):" << std::endl;
		std::vector<int> one;
		printVectorStd(1, one, file_std);
		file_std << "-# Fill : two (size = 5, value = 42):" << std::endl;
		std::vector<int> two(4, 42);
		printVectorStd(1, two, file_std);
		file_std << "-# Range : three (from two.begin() to two.end() ):" << std::endl;
		std::vector<int> three(two.begin(), two.end());
		printVectorStd(1, three, file_std);
		file_std << "-# Copy : four (from three):" << std::endl;
		std::vector<int> four(three);
		printVectorStd(1, four, file_std);
		file_std << "-# Assignation : five (from four):" << std::endl;
		std::vector<int> five;
		five = four;
		printVectorStd(1, five, file_std);
	}
	{
		file << "\t\t -- Assign method: --\n";
		ft::vector<int> v_one(8);
		ft::vector<int> v_two(3);
		ft::vector<int> v_three;
		ft::vector<int> v_four;
		

		for (unsigned long i = 0; i < v_one.size(); ++i)
			v_one[i] = (v_one.size() - i) * 3;
		for (unsigned long i = 0; i < v_two.size(); ++i)
			v_two[i] = (v_two.size() - i) * 5;
		printVector(1, v_one, file);
		printVector(1, v_two, file);
		v_three.assign(v_one.begin(), v_one.end());
		v_one.assign(v_two.begin(), v_two.end());
		v_two.assign(2, 42);
		v_four.assign(5, 21);
		file << "\n## After assign:\n\n";
		printVector(1, v_one, file);
		printVector(1, v_two, file);
		printVector(1, v_three, file);
		printVector(1, v_four, file);
		v_four.assign(7, 24);
		printVector(1, v_four, file);
		file << "\n## Assign on low size:\n\n";
		v_one.assign(6, 72);
		v_two.assign(v_three.begin(), v_three.end());
		printVector(1, v_one, file);
		printVector(1, v_two, file);
	}
	{
		file_std << "\t\t -- Assign method: --\n";
		std::vector<int> v_one(8);
		std::vector<int> v_two(3);
		std::vector<int> v_three;
		std::vector<int> v_four;
		

		for (unsigned long i = 0; i < v_one.size(); ++i)
			v_one[i] = (v_one.size() - i) * 3;
		for (unsigned long i = 0; i < v_two.size(); ++i)
			v_two[i] = (v_two.size() - i) * 5;
		printVectorStd(1, v_one, file_std);
		printVectorStd(1, v_two, file_std);
		v_three.assign(v_one.begin(), v_one.end());
		v_one.assign(v_two.begin(), v_two.end());
		v_two.assign(2, 42);
		v_four.assign(5, 21);
		file_std << "\n## After assign:\n\n";
		printVectorStd(1, v_one, file_std);
		printVectorStd(1, v_two, file_std);
		printVectorStd(1, v_three, file_std);
		printVectorStd(1, v_four, file_std);
		v_four.assign(7, 24);
		printVectorStd(1, v_four, file_std);
		file_std << "\n## Assign on low size:\n\n";
		v_one.assign(6, 72);
		v_two.assign(v_three.begin(), v_three.end());
		printVectorStd(1, v_one, file_std);
		printVectorStd(1, v_two, file_std);
	}
	{
		file << "\n\n\t\t-- at() front() and back() method: --\n";
		ft::vector<int> v_one(8);
		for (unsigned long i = 0; i < v_one.size(); ++i) {
			v_one.at(i) = (v_one.size() - i) * 3;
			file << "v_one.at(" << i << ") = " << v_one.at(i) << "\n";
		}
		printVector(1, v_one, file);

		ft::vector<int> v_one_const(v_one);
		file << "front(): " << v_one_const.front() << " " << v_one.front() << std::endl;
		file << "back(): " << v_one_const.back() << " " << v_one.back() << std::endl;

		try {
			v_one_const.at(v_one_const.size()) = 42;
			file << "v_one_const.at(" << v_one_const.size() << ") = " << v_one_const.at(v_one_const.size()) << "\n";
		}
		catch (std::out_of_range &e) {
			file << "Out of range exception: " << e.what() << std::endl;
		}
		catch (...) {
			file << "Unknown exception\n";
		}
	}
	{
		file_std << "\n\n\t\t-- at() front() and back() method: --\n";
		std::vector<int> v_one(8);
		for (unsigned long i = 0; i < v_one.size(); ++i) {
			v_one.at(i) = (v_one.size() - i) * 3;
			file_std << "v_one.at(" << i << ") = " << v_one.at(i) << "\n";
		}
		printVectorStd(1, v_one, file_std);

		std::vector<int> v_one_const(v_one);
		file_std << "front(): " << v_one_const.front() << " " << v_one.front() << std::endl;
		file_std << "back(): " << v_one_const.back() << " " << v_one.back() << std::endl;

		try {
			v_one_const.at(v_one_const.size()) = 42;
			file_std << "v_one_const.at(" << v_one_const.size() << ") = " << v_one_const.at(v_one_const.size()) << "\n";
		}
		catch (std::out_of_range &e) {
			file_std << "Out of range exception: " << e.what() << std::endl;
		}
		catch (...) {
			file_std << "Unknown exception\n";
		}
	}
	{
		file << "\n\n\t\t-- erase() method: --\n";
		ft::vector<std::string> v_one(10);
		for (unsigned long i = 0; i < v_one.size(); ++i) {
			v_one[i] = std::string((v_one.size() - i), i + 'a');
			file << "v_one[" << i << "] = " << v_one[i] << "\n";
		}
		v_one.erase(v_one.begin() + 3, v_one.begin() + 6);
		file << "After erase(v_one.begin() + 3, v_one.begin() + 6):\n";
		printVector(1, v_one, file);

		v_one.erase(v_one.end() - 3, v_one.end() + 1);
		file << "After erase(v_one.end() - 3, v_one.end() + 1):\n";
		printVector(1, v_one, file);

		v_one.push_back("Hello");
		v_one.push_back("World");
		printVector(1, v_one, file);
		v_one.erase(v_one.begin() + 1, v_one.end() - 1);
		file << "After erase(v_one.begin() + 1, v_one.end() - 1):\n";
		printVector(1, v_one, file);
		
		v_one.push_back("FORTYTWO");
		v_one.push_back("TWENTYONE");
		v_one.push_back("TWELVE");
		v_one.push_back("BLABLA");
		printVector(1, v_one, file);
		v_one.erase(v_one.begin(), v_one.end());
		file << "After erase(v_one.begin(), v_one.end()):\n";
		printVector(1, v_one, file);		
	}
	{
		file_std << "\n\n\t\t-- erase() method: --\n";
		std::vector<std::string> v_one(10);
		for (unsigned long i = 0; i < v_one.size(); ++i) {
			v_one[i] = std::string((v_one.size() - i), i + 'a');
			file_std << "v_one[" << i << "] = " << v_one[i] << "\n";
		}
		v_one.erase(v_one.begin() + 3, v_one.begin() + 6);
		file_std << "After erase(v_one.begin() + 3, v_one.begin() + 6):\n";
		printVectorStd(1, v_one, file_std);

		v_one.erase(v_one.end() - 3, v_one.end() + 1);
		file_std << "After erase(v_one.end() - 3, v_one.end() + 1):\n";
		printVectorStd(1, v_one, file_std);

		v_one.push_back("Hello");
		v_one.push_back("World");
		printVectorStd(1, v_one, file_std);
		v_one.erase(v_one.begin() + 1, v_one.end() - 1);
		file_std << "After erase(v_one.begin() + 1, v_one.end() - 1):\n";
		printVectorStd(1, v_one, file_std);
		
		v_one.push_back("FORTYTWO");
		v_one.push_back("TWENTYONE");
		v_one.push_back("TWELVE");
		v_one.push_back("BLABLA");
		printVectorStd(1, v_one, file_std);
		v_one.erase(v_one.begin(), v_one.end());
		file_std << "After erase(v_one.begin(), v_one.end()):\n";
		printVectorStd(1, v_one, file_std);
	}
	{
		file << "\n\n\t\t-- insert() method: --\n";
		ft::vector<int> v_one(10);
		ft::vector<int> v_two;
		ft::vector<int> v_three;
		for (unsigned long int i = 0; i < v_one.size(); ++i)
			v_one[i] = (v_one.size() - i) * 3;
		printVector(0, v_one, file);

		v_two.insert(v_two.end(), 42);
		v_two.insert(v_two.begin(), 2, 21);
		printVector(0, v_two, file);
		v_two.insert(v_two.end() -2, 42);
		printVector(0, v_two, file);
		v_two.insert(v_two.end(), 2, 84);
		printVector(0, v_two, file);
		v_two.resize(4);
		printVector(0, v_two, file);
		v_two.insert(v_two.begin() + 1, v_one.begin(), v_one.end());
		v_one.clear();
		printVector(0, v_two, file);
		printVector(0, v_one, file);
		for (int i = 0; i < 10; ++i)
			v_three.insert(v_three.end(), i);
		v_three.insert(v_three.begin() + 1, 4, 99);
		printVector(0, v_three, file);
	}
	{
		file_std << "\n\n\t\t-- insert() method: --\n";
		std::vector<int> v_one(10);
		std::vector<int> v_two;
		std::vector<int> v_three;
		for (unsigned long int i = 0; i < v_one.size(); ++i)
			v_one[i] = (v_one.size() - i) * 3;
		printVectorStd(0, v_one, file_std);
		v_two.insert(v_two.end(), 42);
		v_two.insert(v_two.begin(), 2, 21);
		printVectorStd(0, v_two, file_std);
		v_two.insert(v_two.end() -2, 42);
		printVectorStd(0, v_two, file_std);
		v_two.insert(v_two.end(), 2, 84);
		printVectorStd(0, v_two, file_std);
		v_two.resize(4);
		printVectorStd(0, v_two, file_std);
		v_two.insert(v_two.begin() + 1, v_one.begin(), v_one.end());
		v_one.clear();
		printVectorStd(0, v_two, file_std);
		printVectorStd(0, v_one, file_std);
		for (int i = 0; i < 10; ++i)
			v_three.insert(v_three.end(), i);
		v_three.insert(v_three.begin() + 1, 4, 99);
		printVectorStd(0, v_three, file_std);
	}
	{
		file << "\n\n\t\t-- push() & pop() methods: --\n";
		ft::vector<std::string> v_one(8);
		ft::vector<std::string> v_two;
		for (unsigned long int i = 0; i < v_one.size(); ++i) {
			v_one[i] = std::string((v_one.size() - i), i + 'a');
			file << "v_one[" << i << "] = " << v_one[i] << "\n";
		}
		v_one.push_back("AaAaAaAaAaAaAaAaAa");
		v_two.push_back("BbBbBbBbBbBbBbBbBbBb");
		printVector(0, v_one, file);
		printVector(0, v_two, file);
		v_one.pop_back();
		v_two.pop_back();
		printVector(0, v_one, file);
		printVector(0, v_two, file);
	}
	{
		file_std << "\n\n\t\t-- push() & pop() methods: --\n";
		std::vector<std::string> v_one(8);
		std::vector<std::string> v_two;
		for (unsigned long int i = 0; i < v_one.size(); ++i) {
			v_one[i] = std::string((v_one.size() - i), i + 'a');
			file_std << "v_one[" << i << "] = " << v_one[i] << "\n";
		}
		v_one.push_back("AaAaAaAaAaAaAaAaAa");
		v_two.push_back("BbBbBbBbBbBbBbBbBbBb");
		printVectorStd(0, v_one, file_std);
		printVectorStd(0, v_two, file_std);
		v_one.pop_back();
		v_two.pop_back();
		printVectorStd(0, v_one, file_std);
		printVectorStd(0, v_two, file_std);
	}
	{
		file << "\n\n\t\t-- resize() & reserve() methods: --\n";
		const int size = 10;
		ft::vector<int> v_one(size, 20);
		ft::vector<int> v_two;
		ft::vector<int>::iterator it(v_one.begin());
		for (int i = 2; i < size; ++i)
			it[i] = (size - i) * 3;
		printVector(0, v_one, file, true);
		v_one.resize(15, 42);
		printVector(0, v_one, file, true);
		v_one.resize(21, 43);
		printVector(0, v_one, file, true);
		v_one.resize(15);
		printVector(0, v_one, file, true);
		v_one.resize(25, 46);
		printVector(0, v_one, file, true);
		v_one.resize(5);
		printVector(0, v_one, file, true);
		v_one.reserve(5);
		v_one.reserve(3);
		printVector(0, v_one, file, true);
		v_one.resize(66);
		v_one.resize(5);
		printVector(0, v_one, file, true);
		file << "\n is empty: " << v_two.empty() << "\n";
		v_two = v_one;
		file << "\n is empty: " << v_two.empty() << "\n";
		v_one.reserve(v_one.capacity() + 1);
		printVector(1, v_one, file, true);
		printVector(1, v_two, file, true);
		v_two.resize(0);
		file << "\n is empty: " << v_two.empty() << "\n";
		printVector(1, v_two, file, true);
	}
	{
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		file << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			file << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);
		file << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			file << "capacity changed: " << sz << '\n';
			}
		}
	}
	{
		file_std << "\n\n\t\t-- resize() & reserve() methods: --\n";
		const int size = 10;
		std::vector<int> v_one(size, 20);
		std::vector<int> v_two;
		std::vector<int>::iterator it(v_one.begin());
		for (int i = 2; i < size; ++i)
			it[i] = (size - i) * 3;
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(15, 42);
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(21, 43);
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(15);
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(25, 46);
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(5);
		printVectorStd(0, v_one, file_std, true);
		v_one.reserve(5);
		v_one.reserve(3);
		printVectorStd(0, v_one, file_std, true);
		v_one.resize(66);
		v_one.resize(5);
		printVectorStd(0, v_one, file_std, true);
		file_std << "\n is empty: " << v_two.empty() << "\n";
		v_two = v_one;
		file_std << "\n is empty: " << v_two.empty() << "\n";
		v_one.reserve(v_one.capacity() + 1);
		printVectorStd(1, v_one, file_std, true);
		printVectorStd(1, v_two, file_std, true);
		v_two.resize(0);
		file_std << "\n is empty: " << v_two.empty() << "\n";
		printVectorStd(1, v_two, file_std, true);
	}
	{
		std::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		file_std << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
			sz = foo.capacity();
			file_std << "capacity changed: " << sz << '\n';
			}
		}

		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);
		file_std << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
			sz = bar.capacity();
			file_std << "capacity changed: " << sz << '\n';
			}
		}
	}
	{
		file << "\n\n\t\t-- swap() methods: --\n";
		ft::vector<int> v_one(10, 20);
		ft::vector<int> v_two(5, 30);
		ft::vector<int>::const_iterator it(v_one.begin());
		ft::vector<int>::const_iterator it_two(v_two.begin());
		file << "Before swap:\n";
		file << "v_one:\n";
		printVector(1, v_one, file);
		file << "v_two:\n";
		printVector(1, v_two, file);

		v_one.swap(v_two);

		file << "After swap:\n";
		file << "v_one:\n";
		printVector(1, v_one, file);
		file << "v_two:\n";
		printVector(1, v_two, file);

		file << "Iterator validity after swap:\n";
		file << "v_one: " << (it == v_two.begin()) << "\n";
		file << "v_two: " << (it_two == v_one.begin()) << "\n";
	}
	{
		file_std << "\n\n\t\t-- swap() methods: --\n";
		std::vector<int> v_one(10, 20);
		std::vector<int> v_two(5, 30);
		std::vector<int>::const_iterator it(v_one.begin());
		std::vector<int>::const_iterator it_two(v_two.begin());
		file_std << "Before swap:\n";
		file_std << "v_one:\n";
		printVectorStd(1, v_one, file_std);
		file_std << "v_two:\n";
		printVectorStd(1, v_two, file_std);

		v_one.swap(v_two);

		file_std << "After swap:\n";
		file_std << "v_one:\n";
		printVectorStd(1, v_one, file_std);
		file_std << "v_two:\n";
		printVectorStd(1, v_two, file_std);

		file_std << "Iterator validity after swap:\n";
		file_std << "v_one: " << (it == v_two.begin()) << "\n";
		file_std << "v_two: " << (it_two == v_one.begin()) << "\n";
	}
	file.close();	
	file_std.close();	
}

inline void		ft_vector_tester( void )
{
	ft_iterators();
	ft_const_iterators();
	ft_reverse_iterators();
	ft_vector_tests();
}