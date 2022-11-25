/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:54:29 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 12:08:45 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include "../map.hpp"

inline void	ft_iterator(std::ostream &file, std::ostream &file_std)
{
	{
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "----------------- iterator ------------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		ft::map<int, std::string>		ft_map;
		ft::map<int, std::string>::iterator	it;
		ft::map<int, std::string>::iterator	ite;
		ft::map<int, std::string>::reverse_iterator	it2;
		ft::map<int, std::string>::reverse_iterator	ite2;

		ft_map[1] = "one";
		ft_map[2] = "two";
		ft_map[3] = "three";
		ft_map[4] = "four";

		it = ft_map.begin();
		ite = ft_map.end();
		it2 = ft_map.rbegin();
		ite2 = ft_map.rend();
		file << "map:" << std::endl;
		file << "begin: " << it->first << " " << it->second << std::endl;
		while (it != ite)
		{
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
			it++;
		}
		file << std::endl << "reverse:" << std::endl;
		file << "rbegin: " << it2->first << " " << it2->second << std::endl;
		while (it2 != ite2)
		{
			file << "||  Key: " << it2->first << "\t||  Value: " << it2->second << "\n";
			it2++;
		}
		file << std::endl << "operator overloads:" << std::endl;
		file << "operator==: " << (ft_map.begin() == ft_map.end()) << std::endl;
		file << "operator!=: " << (ft_map.begin() != ft_map.end()) << std::endl;
		file << "operator++: " << (++ft_map.begin())->first << std::endl;
		file << "operator--: " << (--ft_map.end())->first << std::endl;
		file << "operator->: " << ft_map.begin()->first << std::endl;
		file << "operator[]: " << ft_map[1] << std::endl;
		file << "operator = :" << std::endl;
		it = ft_map.begin();
		file << "before: " << it->first << " " << it->second << std::endl;
		it = --ft_map.end();
		file << "after: " << it->first << " " << it->second << std::endl;
		it2 = ft_map.rbegin();
		file << "before: " << it2->first << " " << it2->second << std::endl;
		it2 = --ft_map.rend();
		file << "after: " << it2->first << " " << it2->second << std::endl;
		file << "operator*: " << it->first << std::endl;
		file << "operator->: " << it->first << std::endl;
		file << "operator[]: " << it->first << std::endl;
		
	}
	{
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "----------------- iterator ------------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		std::map<int, std::string>		std_map;
		std::map<int, std::string>::iterator	it;
		std::map<int, std::string>::iterator	ite;
		std::map<int, std::string>::reverse_iterator	it2;
		std::map<int, std::string>::reverse_iterator	ite2;

		std_map[1] = "one";
		std_map[2] = "two";
		std_map[3] = "three";
		std_map[4] = "four";

		it = std_map.begin();
		ite = std_map.end();
		it2 = std_map.rbegin();
		ite2 = std_map.rend();
		file_std << "map:" << std::endl;
		file_std << "begin: " << it->first << " " << it->second << std::endl;
		while (it != ite)
		{
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
			it++;
		}
		file_std << std::endl << "reverse:" << std::endl;
		file_std << "rbegin: " << it2->first << " " << it2->second << std::endl;
		while (it2 != ite2)
		{
			file_std << "||  Key: " << it2->first << "\t||  Value: " << it2->second << "\n";
			it2++;
		}
		file_std << std::endl << "operator overloads:" << std::endl;
		file_std << "operator==: " << (std_map.begin() == std_map.end()) << std::endl;
		file_std << "operator!=: " << (std_map.begin() != std_map.end()) << std::endl;
		file_std << "operator++: " << (++std_map.begin())->first << std::endl;
		file_std << "operator--: " << (--std_map.end())->first << std::endl;
		file_std << "operator->: " << std_map.begin()->first << std::endl;
		file_std << "operator[]: " << std_map[1] << std::endl;
		file_std << "operator = :" << std::endl;
		it = std_map.begin();
		file_std << "before: " << it->first << " " << it->second << std::endl;
		it = --std_map.end();
		file_std << "after: " << it->first << " " << it->second << std::endl;
		it2 = std_map.rbegin();
		file_std << "before: " << it2->first << " " << it2->second << std::endl;
		it2 = --std_map.rend();
		file_std << "after: " << it2->first << " " << it2->second << std::endl;
		file_std << "operator*: " << it->first << std::endl;
		file_std << "operator->: " << it->first << std::endl;
		file_std << "operator[]: " << it->first << std::endl;
	}
	{
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "-------------- CONST iterator ---------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		ft::map<int, std::string>		ft_map;
		ft::map<int, std::string>::const_iterator	it;
		ft::map<int, std::string>::const_iterator	ite;
		ft::map<int, std::string>::const_reverse_iterator	it2;
		ft::map<int, std::string>::const_reverse_iterator	ite2;

		ft_map[1] = "one";
		ft_map[2] = "two";
		ft_map[3] = "three";
		ft_map[4] = "four";

		it = ft_map.begin();
		ite = ft_map.end();
		it2 = ft_map.rbegin();
		ite2 = ft_map.rend();
		file << "map:" << std::endl;
		file << "begin: " << it->first << " " << it->second << std::endl;
		while (it != ite)
		{
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
			it++;
		}
		file << std::endl << "reverse:" << std::endl;
		file << "rbegin: " << it2->first << " " << it2->second << std::endl;
		while (it2 != ite2)
		{
			file << "||  Key: " << it2->first << "\t||  Value: " << it2->second << "\n";
			it2++;
		}
		file << std::endl << "operator overloads:" << std::endl;
		file << "operator==: " << (ft_map.begin() == ft_map.end()) << std::endl;
		file << "operator!=: " << (ft_map.begin() != ft_map.end()) << std::endl;
		file << "operator++: " << (++ft_map.begin())->first << std::endl;
		file << "operator--: " << (--ft_map.end())->first << std::endl;
		file << "operator->: " << ft_map.begin()->first << std::endl;
		file << "operator[]: " << ft_map[1] << std::endl;
		file << "operator = :" << std::endl;
		it = ft_map.begin();
		file << "before: " << it->first << " " << it->second << std::endl;
		it = --ft_map.end();
		file << "after: " << it->first << " " << it->second << std::endl;
		it2 = ft_map.rbegin();
		file << "before: " << it2->first << " " << it2->second << std::endl;
		it2 = --ft_map.rend();
		file << "after: " << it2->first << " " << it2->second << std::endl;
		file << "operator*: " << it->first << std::endl;
		file << "operator->: " << it->first << std::endl;
		file << "operator[]: " << it->first << std::endl;
	}
	{
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "-------------- CONST iterator ---------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		std::map<int, std::string>		std_map;
		std::map<int, std::string>::const_iterator	it;
		std::map<int, std::string>::const_iterator	ite;
		std::map<int, std::string>::const_reverse_iterator	it2;
		std::map<int, std::string>::const_reverse_iterator	ite2;

		std_map[1] = "one";
		std_map[2] = "two";
		std_map[3] = "three";
		std_map[4] = "four";

		it = std_map.begin();
		ite = std_map.end();
		it2 = std_map.rbegin();
		ite2 = std_map.rend();
		file_std << "map:" << std::endl;
		file_std << "begin: " << it->first << " " << it->second << std::endl;
		while (it != ite)
		{
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
			it++;
		}
		file_std << std::endl << "reverse:" << std::endl;
		file_std << "rbegin: " << it2->first << " " << it2->second << std::endl;
		while (it2 != ite2)
		{
			file_std << "||  Key: " << it2->first << "\t||  Value: " << it2->second << "\n";
			it2++;
		}
		file_std << std::endl << "operator overloads:" << std::endl;
		file_std << "operator==: " << (std_map.begin() == std_map.end()) << std::endl;
		file_std << "operator!=: " << (std_map.begin() != std_map.end()) << std::endl;
		file_std << "operator++: " << (++std_map.begin())->first << std::endl;
		file_std << "operator--: " << (--std_map.end())->first << std::endl;
		file_std << "operator->: " << std_map.begin()->first << std::endl;
		file_std << "operator[]: " << std_map[1] << std::endl;
		file_std << "operator = :" << std::endl;
		it = std_map.begin();
		file_std << "before: " << it->first << " " << it->second << std::endl;
		it = --std_map.end();
		file_std << "after: " << it->first << " " << it->second << std::endl;
		it2 = std_map.rbegin();
		file_std << "before: " << it2->first << " " << it2->second << std::endl;
		it2 = --std_map.rend();
		file_std << "after: " << it2->first << " " << it2->second << std::endl;
		file_std << "operator*: " << it->first << std::endl;
		file_std << "operator->: " << it->first << std::endl;
		file_std << "operator[]: " << it->first << std::endl;
	}
}

inline void	ft_map(std::ostream &file, std::ostream &file_std)
{
	{		
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "----------------- CONSTRUCTORS --------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		ft::map<int, std::string>		ft_map;
		ft_map[1] = "one";
		ft_map[2] = "two";
		ft_map[3] = "three";
		ft_map[4] = "four";
		ft_map[5] = "five";
		ft::map<int, std::string>		ft_map2(ft_map);
		ft::map<int, std::string>		ft_map3(ft_map.begin(), ft_map.end());
		ft::map<int, std::string>		ft_map4(ft_map.rbegin(), ft_map.rend());
		ft::map<int, std::string>		ft_map5 = ft_map2;

		file << "map (original) :" << std::endl;
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << std::endl << "map2 (Copy):" << std::endl;
		for (ft::map<int, std::string>::iterator it = ft_map2.begin(); it != ft_map2.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << std::endl << "map3 (range):" << std::endl;
		for (ft::map<int, std::string>::iterator it = ft_map3.begin(); it != ft_map3.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << std::endl << "map4 (reverse range):" << std::endl;
		for (ft::map<int, std::string>::iterator it = ft_map4.begin(); it != ft_map4.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << std::endl << "map5(assignment):" << std::endl;
		for (ft::map<int, std::string>::iterator it = ft_map5.begin(); it != ft_map5.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";

		file << std::endl << "---------------------------------------------" << std::endl;
		file << "------------------- ACCESS ------------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		file << "map[1]: " << ft_map[1] << std::endl;
		file << "map[2]: " << ft_map[2] << std::endl;
		file << "map[3]: " << ft_map[3] << std::endl;
		file << "map[4]: " << ft_map[4] << std::endl;
		file << "map[5]: " << ft_map[5] << std::endl;
		file << "map.at(1): " << ft_map.at(1) << std::endl;
		file << "map.at(2): " << ft_map.at(2) << std::endl;
		try
		{
			file << "map.at(7): " << ft_map.at(7) << std::endl;
		}
		catch (std::exception &e)
		{
			file << "map.at(7): " << e.what() << std::endl;
		}
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "------------------- CAPACITY ----------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		file << "map.empty(): " << ft_map.empty() << std::endl;
		file << "map.size(): " << ft_map.size() << std::endl;
		file << "map.max_size(): " << ft_map.max_size() << std::endl;
		
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "------------------- MODIFIERS ---------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		file << "map.insert(6, six): " << std::endl;
		ft_map.insert(ft::make_pair(6, "six"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.insert(7, seven): " << std::endl;
		ft_map.insert(ft::make_pair(7, "seven"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.insert(8, eight): " << std::endl;
		ft_map.insert(ft::make_pair(8, "eight"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.insert(9, nine): " << std::endl;
		ft_map.insert(ft::make_pair(9, "nine"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.insert(10, ten): " << std::endl;
		ft_map.insert(ft::make_pair(10, "ten"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.erase(10): " << std::endl;
		ft_map.erase(10);
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.erase(1, 3): " << std::endl;
		ft_map.erase(ft_map.begin(), ft_map.find(3));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.insert(1, 3, one): " << std::endl;
		ft_map.insert(ft_map.begin(), ft::make_pair(1, "one"));
		ft_map.insert(ft_map.begin(), ft::make_pair(2, "two"));
		ft_map.insert(ft_map.begin(), ft::make_pair(3, "three"));
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map.swap(map2): " << std::endl;
		ft_map.swap(ft_map2);
		for (ft::map<int, std::string>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "map2.clear()" << std::endl;
		ft_map2.clear();
		for (ft::map<int, std::string>::iterator it = ft_map2.begin(); it != ft_map2.end(); it++)
			file << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file << "Is map2 empty ? : (0) no (1) yes : " << ft_map2.empty() << std::endl;
		file << "map2.size(): " << ft_map2.size() << std::endl;
		
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "-------------------- LOOKUP -----------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		file << "map.find(1): " << ft_map.find(1)->second << std::endl;
		file << "map.find(2): " << ft_map.find(2)->second << std::endl;
		file << "map.find(3): " << ft_map.find(3)->second << std::endl;
		file << "map.find(4): " << ft_map.find(4)->second << std::endl;
		file << "map.find(5): " << ft_map.find(5)->second << std::endl;
		file << "map.count(1): " << ft_map.count(1) << std::endl;
		file << "map.count(2): " << ft_map.count(2) << std::endl;
		file << "map.count(3): " << ft_map.count(3) << std::endl;
		file << "map.count(4): " << ft_map.count(4) << std::endl;
		file << "map.count(5): " << ft_map.count(5) << std::endl;
		file << "map.count(6): " << ft_map.count(6) << std::endl;
		file << "map.lower_bound(1): " << ft_map.lower_bound(1)->second << std::endl;
		file << "map.lower_bound(2): " << ft_map.lower_bound(2)->second << std::endl;
		file << "map.lower_bound(3): " << ft_map.lower_bound(3)->second << std::endl;
		file << "map.lower_bound(4): " << ft_map.lower_bound(4)->second << std::endl;
		file << "map.lower_bound(5): " << ft_map.lower_bound(5)->second << std::endl;
		file << "map.upper_bound(1): " << ft_map.upper_bound(1)->second << std::endl;
		file << "map.upper_bound(2): " << ft_map.upper_bound(2)->second << std::endl;
		file << "map.upper_bound(3): " << ft_map.upper_bound(3)->second << std::endl;
		file << "map.upper_bound(4): " << ft_map.upper_bound(4)->second << std::endl;
		file << "map.equal_range(1): " << ft_map.equal_range(1).first->second << " " << ft_map.equal_range(1).second->second << std::endl;
		file << "map.equal_range(2): " << ft_map.equal_range(2).first->second << " " << ft_map.equal_range(2).second->second << std::endl;
		file << "map.equal_range(3): " << ft_map.equal_range(3).first->second << " " << ft_map.equal_range(3).second->second << std::endl;
		file << "map.equal_range(4): " << ft_map.equal_range(4).first->second << " " << ft_map.equal_range(4).second->second << std::endl;
		
		file << std::endl << "---------------------------------------------" << std::endl;
		file << "------------------- OBSERVERS ---------------" << std::endl;
		file << "---------------------------------------------" << std::endl;
		file << "map.key_comp(): " << ft_map.key_comp()(1, 2) << std::endl;
		file << "map.value_comp(): " << ft_map.value_comp()(ft::make_pair(1, "one"), ft::make_pair(2, "two")) << std::endl;
	}
	{
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "----------------- CONSTRUCTORS --------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		std::map<int, std::string>		std_map;
		std_map[1] = "one";
		std_map[2] = "two";
		std_map[3] = "three";
		std_map[4] = "four";
		std_map[5] = "five";
		std::map<int, std::string>		std_map2(std_map);
		std::map<int, std::string>		std_map3(std_map.begin(), std_map.end());
		std::map<int, std::string>		std_map4(std_map.rbegin(), std_map.rend());
		std::map<int, std::string>		std_map5 = std_map2;

		file_std << "map (original) :" << std::endl;
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << std::endl << "map2 (Copy):" << std::endl;
		for (std::map<int, std::string>::iterator it = std_map2.begin(); it != std_map2.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << std::endl << "map3 (range):" << std::endl;
		for (std::map<int, std::string>::iterator it = std_map3.begin(); it != std_map3.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << std::endl << "map4 (reverse range):" << std::endl;
		for (std::map<int, std::string>::iterator it = std_map4.begin(); it != std_map4.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << std::endl << "map5(assignment):" << std::endl;
		for (std::map<int, std::string>::iterator it = std_map5.begin(); it != std_map5.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "------------------- ACCESS ------------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		file_std << "map[1]: " << std_map[1] << std::endl;
		file_std << "map[2]: " << std_map[2] << std::endl;
		file_std << "map[3]: " << std_map[3] << std::endl;
		file_std << "map[4]: " << std_map[4] << std::endl;
		file_std << "map[5]: " << std_map[5] << std::endl;
		file_std << "map.at(1): " << std_map.at(1) << std::endl;
		file_std << "map.at(2): " << std_map.at(2) << std::endl;
		try
		{
			file_std << "map.at(7): " << std_map.at(7) << std::endl;
		}
		catch (std::exception &e)
		{
			file_std << "map.at(7): " << e.what() << std::endl;
		}
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "------------------- CAPACITY ----------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		file_std << "map.empty(): " << std_map.empty() << std::endl;
		file_std << "map.size(): " << std_map.size() << std::endl;
		file_std << "map.max_size(): " << std_map.max_size() << std::endl;
		
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "------------------- MODIFIERS ---------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		file_std << "map.insert(6, six): " << std::endl;
		std_map.insert(std::make_pair(6, "six"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.insert(7, seven): " << std::endl;
		std_map.insert(std::make_pair(7, "seven"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.insert(8, eight): " << std::endl;
		std_map.insert(std::make_pair(8, "eight"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.insert(9, nine): " << std::endl;
		std_map.insert(std::make_pair(9, "nine"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.insert(10, ten): " << std::endl;
		std_map.insert(std::make_pair(10, "ten"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.erase(10): " << std::endl;
		std_map.erase(10);
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.erase(1, 3): " << std::endl;
		std_map.erase(std_map.begin(), std_map.find(3));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.insert(1, 3, one): " << std::endl;
		std_map.insert(std_map.begin(), std::make_pair(1, "one"));
		std_map.insert(std_map.begin(), std::make_pair(2, "two"));
		std_map.insert(std_map.begin(), std::make_pair(3, "three"));
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map.swap(map2): " << std::endl;
		std_map.swap(std_map2);
		for (std::map<int, std::string>::iterator it = std_map.begin(); it != std_map.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "map2.clear()" << std::endl;
		std_map2.clear();
		for (std::map<int, std::string>::iterator it = std_map2.begin(); it != std_map2.end(); it++)
			file_std << "||  Key: " << it->first << "\t||  Value: " << it->second << "\n";
		file_std << "Is map2 empty ? : (0) no (1) yes : " << std_map2.empty() << std::endl;
		file_std << "map2.size(): " << std_map2.size() << std::endl;
		
		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "-------------------- LOOKUP -----------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		file_std << "map.find(1): " << std_map.find(1)->second << std::endl;
		file_std << "map.find(2): " << std_map.find(2)->second << std::endl;
		file_std << "map.find(3): " << std_map.find(3)->second << std::endl;
		file_std << "map.find(4): " << std_map.find(4)->second << std::endl;
		file_std << "map.find(5): " << std_map.find(5)->second << std::endl;
		file_std << "map.count(1): " << std_map.count(1) << std::endl;
		file_std << "map.count(2): " << std_map.count(2) << std::endl;
		file_std << "map.count(3): " << std_map.count(3) << std::endl;
		file_std << "map.count(4): " << std_map.count(4) << std::endl;
		file_std << "map.count(5): " << std_map.count(5) << std::endl;
		file_std << "map.count(6): " << std_map.count(6) << std::endl;
		file_std << "map.lower_bound(1): " << std_map.lower_bound(1)->second << std::endl;
		file_std << "map.lower_bound(2): " << std_map.lower_bound(2)->second << std::endl;
		file_std << "map.lower_bound(3): " << std_map.lower_bound(3)->second << std::endl;
		file_std << "map.lower_bound(4): " << std_map.lower_bound(4)->second << std::endl;
		file_std << "map.lower_bound(5): " << std_map.lower_bound(5)->second << std::endl;
		file_std << "map.upper_bound(1): " << std_map.upper_bound(1)->second << std::endl;
		file_std << "map.upper_bound(2): " << std_map.upper_bound(2)->second << std::endl;
		file_std << "map.upper_bound(3): " << std_map.upper_bound(3)->second << std::endl;
		file_std << "map.upper_bound(4): " << std_map.upper_bound(4)->second << std::endl;
		file_std << "map.equal_range(1): " << std_map.equal_range(1).first->second << " " << std_map.equal_range(1).second->second << std::endl;
		file_std << "map.equal_range(2): " << std_map.equal_range(2).first->second << " " << std_map.equal_range(2).second->second << std::endl;
		file_std << "map.equal_range(3): " << std_map.equal_range(3).first->second << " " << std_map.equal_range(3).second->second << std::endl;
		file_std << "map.equal_range(4): " << std_map.equal_range(4).first->second << " " << std_map.equal_range(4).second->second << std::endl;

		file_std << std::endl << "---------------------------------------------" << std::endl;
		file_std << "------------------- OBSERVERS ---------------" << std::endl;
		file_std << "---------------------------------------------" << std::endl;
		file_std << "map.key_comp(): " << std_map.key_comp()(1, 2) << std::endl;
		file_std << "map.value_comp(): " << std_map.value_comp()(std::make_pair(1, "one"), std::make_pair(2, "two")) << std::endl;		
	}
}

inline void ft_map_tester( void )
{
	std::fstream file;
	std::fstream file_std;
	file.open("my_map_test.txt", std::ios::out | std::ios::trunc);
	file_std.open("std_map_test.txt", std::ios::out | std::ios::trunc);
	ft_iterator(file, file_std);
	ft_map(file ,file_std);
	file.close();
	file_std.close();
}
