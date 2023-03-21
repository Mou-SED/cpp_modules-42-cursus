/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:32:58 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 18:33:38 by moseddik         ###   ########.fr       */
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

	for ( size_t i = 0; i <= input.size(); ++i )
	{
		size_t iOperator = input.find_first_of(operators);
		if ( myStack.size() )
		i = 0;
		while ( i < iOperator )
		{
			myStack.push(input[i] - 48);
			i++;
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
			std::cout << "Error : RPN Format is invalid!" << std::endl;
			exit(1);
		}
	}
	return res;
}

