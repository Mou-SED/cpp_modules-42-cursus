/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:32:58 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 21:20:59 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

enum Operators
{
    MULTIPLY = '*',
    DIVIDE = '/',
    ADD = '+',
    SUBTRACT = '-'
};

std::string	removeSpaces( std::string & input )
{
	std::string out = "";

	for ( size_t i = 0; i < input.size(); ++i )
	{
		if ( input[i] != ' ' and input[i] != '\t' )
			out.push_back(input[i]);
	}
	return out;
}

bool	check_format( std::string input )
{
	std::string operators = "*/+-";

	for ( size_t i = 0; i < input.size(); ++i )
	{
		bool oValid = false;
		if ( input[i] == '*' or input[i] == '/' or input[i] == '+' or input[i] == '-' )
			oValid = true;
		if ( oValid == false and !isdigit(input[i]) )
			return false;
	}
	if ( input.front() == '*' or input.front() == '/' or input.front() == '+' or input.front() == '-' )
		return false;
	if ( isdigit(input.back()) )
		return false;
	return true;
}

int	calculate( std::string & input )
{
	int res = 0;
	std::string operators = "*/+-";
	std::stack<int> myStack;
	size_t i;
	while (!input.empty())
	{
		i = 0;
		size_t iOperator = input.find_first_of(operators);
		while ( i < iOperator )
		{
			myStack.push(input[i] - 48);
			i++;
		}
		if (myStack.size() <= 1 and iOperator != std::string::npos)
		{
			std::cerr << RED << "Error : RPN Format is invalid!" << RESET << std::endl;
			exit(1);
		}
		int num1 = myStack.top();
		myStack.pop();
		int num2 = myStack.top();
		myStack.pop();
		switch (input[iOperator])
		{
			case MULTIPLY:
        		res = num2 * num1;
				break;
			case DIVIDE:
				if (num1 == 0)
					throw 404;
				res = num2 / num1;
				break;
			case ADD:
				res = num2 + num1;
				break;
			case SUBTRACT:
				res = num2 - num1;
				break;
		}
		myStack.push(res);
		input = input.substr(iOperator + 1);
		if ( isdigit(input.front()) and myStack.size() > 1 )
		{
			std::cerr << RED << "Error : RPN Format is invalid!" << RESET << std::endl;
			exit(1);
		}
		i++;
	}
	if (myStack.size() != 1)
	{
		std::cerr << RED << "Error : RPN Format is invalid!" << RESET << std::endl;
		exit(1);
	}
	return res;
}

