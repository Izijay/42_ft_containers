/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:41:11 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/12 14:17:39 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.cpp"
#include "map_test.cpp"
#include "stack_test.cpp"
#include <iostream>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./tester [container]" << std::endl;
		std::cerr << "Available containers: vector, map, stack" << std::endl;
		return 1;
	}
	std::string container(argv[1]);
	if (container == "vector")
		ft_vector_tester();
	else if (container == "map")
		ft_map_tester();
	else if (container == "stack")
		ft_stack_tester();
	else
	{
		std::cerr << "Usage: ./tester [container]" << std::endl;
		std::cerr << "Available containers: vector, map, stack" << std::endl;
		return 1;
	}
	return 0;
}