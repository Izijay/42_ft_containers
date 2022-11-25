/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:27:09 by mdupuis           #+#    #+#             */
/*   Updated: 2022/09/13 10:40:20 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <stack>
#include "../stack.hpp"

inline void	ft_stack(std::fstream &file, std::ostream &file_std)
{
	{
		ft::stack<int> mystack;
		ft::stack<int> mystack2;
		file << "------------------------------------------------------------" << std::endl;
		file << "----------------------- STACK TEST -------------------------" << std::endl;
		file << "------------------------------------------------------------" << std::endl << std::endl;
		
		file << "----------------------- CONSTRUCTOR ------------------------" << std::endl;
		file << "mystack.size() = " << mystack.size() << std::endl;
		file << "mystack.empty() = " << mystack.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		file << "mystack2.size() = " << mystack2.size() << std::endl;
		file << "mystack2.empty() = " << mystack2.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		
		
		file << std::endl << "----------------------- PUSH -------------------------------" << std::endl;
		file << std::endl << "-- Pushing 10, 20, 30 on mystack --" << std::endl;
		mystack.push(10);
		mystack.push(20);
		mystack.push(30);
		file << std::endl << "-- Pushing 1 to 5 on mystack2 --" << std::endl;
		for (int i = 1; i <= 5; ++i) 
			mystack2.push(i);
		file << "------------------------------------------------------------" << std::endl << std::endl;
		
		
		file << "--------------- TOP -- SIZE -- EMPTY -----------------------" << std::endl;
		file << "mystack.top() is now " << mystack.top() << std::endl;
		file << "mystack.size() is now " << mystack.size() << std::endl;
		file << "mystack.empty() is now " << mystack.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		
		
		file << std::endl << "---------------------- COMPARE -----------------------------" << std::endl;
		file << "operator== (mystack == mystack): " << (mystack == mystack) << std::endl;
		file << "operator!= (mystack != mystack): " << (mystack != mystack) << std::endl;
		file << "operator< (mystack < mystack): " << (mystack < mystack) << std::endl;
		file << "operator> (mystack > mystack): " << (mystack > mystack) << std::endl;
		file << "operator<= (mystack <= mystack): " << (mystack <= mystack) << std::endl;
		file << "operator>= (mystack >= mystack): " << (mystack >= mystack) << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		file << "operator== (mystack == mystack2): " << (mystack == mystack2) << std::endl;
		file << "operator!= (mystack != mystack2): " << (mystack != mystack2) << std::endl;
		file << "operator< (mystack < mystack2): " << (mystack < mystack2) << std::endl;
		file << "operator> (mystack > mystack2): " << (mystack > mystack2) << std::endl;
		file << "operator<= (mystack <= mystack2): " << (mystack <= mystack2) << std::endl;
		file << "operator>= (mystack >= mystack2): " << (mystack >= mystack2) << std::endl;


		file << std::endl << "------------------------ POP -------------------------------" << std::endl;
		file << "mystack.top() is now " << mystack.top() << std::endl;
		file << "mystack.size() is now " << mystack.size() << std::endl;
		file << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file << "mystack.top() is now " << mystack.top() << std::endl;
		file << "mystack.size() is now " << mystack.size() << std::endl;
		file << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file << "mystack.top() is now " << mystack.top() << std::endl;
		file << "mystack.size() is now " << mystack.size() << std::endl;
		file << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file << "Can't display top(), mystack is empty" << std::endl;
		file << "mystack.size() is now " << mystack.size() << std::endl;
		file << "mystack.empty() is now " << mystack.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;; 
		mystack2.pop();
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file << "mystack2.top() is now " << mystack2.top() << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file << "Can't display top(), mystack2 is empty" << std::endl;
		file << "mystack2.size() is now " << mystack2.size() << std::endl;
		file << "mystack2.empty() is now " << mystack2.empty() << std::endl;
		file << "------------------------------------------------------------" << std::endl;
	}
	{
		std::stack<int> mystack;
		std::stack<int> mystack2;
		file_std << "------------------------------------------------------------" << std::endl;
		file_std << "----------------------- STACK TEST -------------------------" << std::endl;
		file_std << "------------------------------------------------------------" << std::endl << std::endl;
		
		file_std << "----------------------- CONSTRUCTOR ------------------------" << std::endl;
		file_std << "mystack.size() = " << mystack.size() << std::endl;
		file_std << "mystack.empty() = " << mystack.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		file_std << "mystack2.size() = " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() = " << mystack2.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		
		
		file_std << std::endl << "----------------------- PUSH -------------------------------" << std::endl;
		file_std << std::endl << "-- Pushing 10, 20, 30 on mystack --" << std::endl;
		mystack.push(10);
		mystack.push(20);
		mystack.push(30);
		file_std << std::endl << "-- Pushing 1 to 5 on mystack2 --" << std::endl;
		for (int i = 1; i <= 5; ++i) 
			mystack2.push(i);
		file_std << "------------------------------------------------------------" << std::endl << std::endl;
		
		
		file_std << "--------------- TOP -- SIZE -- EMPTY -----------------------" << std::endl;
		file_std << "mystack.top() is now " << mystack.top() << std::endl;
		file_std << "mystack.size() is now " << mystack.size() << std::endl;
		file_std << "mystack.empty() is now " << mystack.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		
		
		file_std << std::endl << "---------------------- COMPARE -----------------------------" << std::endl;
		file_std << "operator== (mystack == mystack): " << (mystack == mystack) << std::endl;
		file_std << "operator!= (mystack != mystack): " << (mystack != mystack) << std::endl;
		file_std << "operator< (mystack < mystack): " << (mystack < mystack) << std::endl;
		file_std << "operator> (mystack > mystack): " << (mystack > mystack) << std::endl;
		file_std << "operator<= (mystack <= mystack): " << (mystack <= mystack) << std::endl;
		file_std << "operator>= (mystack >= mystack): " << (mystack >= mystack) << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		file_std << "operator== (mystack == mystack2): " << (mystack == mystack2) << std::endl;
		file_std << "operator!= (mystack != mystack2): " << (mystack != mystack2) << std::endl;
		file_std << "operator< (mystack < mystack2): " << (mystack < mystack2) << std::endl;
		file_std << "operator> (mystack > mystack2): " << (mystack > mystack2) << std::endl;
		file_std << "operator<= (mystack <= mystack2): " << (mystack <= mystack2) << std::endl;
		file_std << "operator>= (mystack >= mystack2): " << (mystack >= mystack2) << std::endl;


		file_std << std::endl << "------------------------ POP -------------------------------" << std::endl;
		file_std << "mystack.top() is now " << mystack.top() << std::endl;
		file_std << "mystack.size() is now " << mystack.size() << std::endl;
		file_std << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file_std << "mystack.top() is now " << mystack.top() << std::endl;
		file_std << "mystack.size() is now " << mystack.size() << std::endl;
		file_std << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file_std << "mystack.top() is now " << mystack.top() << std::endl;
		file_std << "mystack.size() is now " << mystack.size() << std::endl;
		file_std << "mystack.empty() is now " << mystack.empty() << std::endl << std::endl;
		mystack.pop();
		file_std << "Can't display top(), mystack is empty" << std::endl;
		file_std << "mystack.size() is now " << mystack.size() << std::endl;
		file_std << "mystack.empty() is now " << mystack.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;; 
		mystack2.pop();
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file_std << "mystack2.top() is now " << mystack2.top() << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl << std::endl;
		mystack2.pop();
		file_std << "Can't display top(), mystack2 is empty" << std::endl;
		file_std << "mystack2.size() is now " << mystack2.size() << std::endl;
		file_std << "mystack2.empty() is now " << mystack2.empty() << std::endl;
		file_std << "------------------------------------------------------------" << std::endl;
	}
}
 inline void 	ft_stack_tester( void )
 {
	std::fstream file_stack;
	file_stack.open("my_stack_test.txt", std::ios::out | std::ios::trunc);
	std::fstream file_stack_std;
	file_stack_std.open("std_stack_test.txt", std::ios::out | std::ios::trunc);
	ft_stack(file_stack, file_stack_std);
	file_stack.close();
	file_stack_std.close();
 }