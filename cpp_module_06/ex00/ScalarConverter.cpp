/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:50:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/14 12:42:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::LiteralType ScalarConverter::_literalType = UNKNOWN;

ScalarConverter::ScalarConverter( void )
{
	return ;
}

ScalarConverter::ScalarConverter( ScalarConverter const & src )
{
	this->_literalType = src._literalType;
	return ;
}

ScalarConverter::~ScalarConverter( void )
{
	return ;
}

ScalarConverter &	ScalarConverter::operator=( ScalarConverter const & other )
{
	if (this != &other)
	{
		this->_literalType = other.getLiteralType();
	}
	return (*this);
}

void		ScalarConverter::setLiteralType( LiteralType type )
{
	_literalType = type;
	return ;
}

ScalarConverter::LiteralType	ScalarConverter::getLiteralType( void )
{
	return (ScalarConverter::_literalType);
}

void					ScalarConverter::convert( std::string & input )
{
	switch (ScalarConverter::getLiteralType())
		{
			case (ScalarConverter::CHAR):
				ScalarConverter::convChar( input );
				break;
			case (ScalarConverter::INTEGER):
				ScalarConverter::convInt( input );
				break;
			case (ScalarConverter::FLOAT):
				ScalarConverter::convFloat( input );
				break;
			case (ScalarConverter::DOUBLE):
				ScalarConverter::convDouble( input );
				break;
			default:
				break ;
		}
	return ;
}

bool check_input(std::string &str)
{
	bool hasDot = false;
	bool hasFloat = false;
	if (str == "+inf" || str == "-inf" || str == "+inff"
			|| str == "-inff" || str == "nan" || str == "nanf")
		return (true);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i != 0 && (str[i] != 'f' && str[i] != '.'
				&& str[i] != '+' && str[i] != '-' && !isdigit(str[i])) )
			return false;
		if (str[i] == '.')
		{
			if (hasDot)
                return false;
            else
                hasDot = true;
		}
		if (str[i] == 'f')
		{
			if (hasFloat)
                return false;
            else
                hasFloat = true;
		}
	}
	if (!hasDot && hasFloat)
		return false;
	return true;
}

void	parsing( std::string const & input )
{
	if (input.size() == 1)
		ScalarConverter::setLiteralType(ScalarConverter::CHAR);
	else if (input == "+inf" || input == "-inf" || input == "+inff"
			|| input == "-inff" || input == "nan" || input == "nanf")
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}
	else if (input.find(".") != std::string::npos)
	{
		if (input.find("f") != std::string::npos)
			ScalarConverter::setLiteralType(ScalarConverter::FLOAT);
		else
			ScalarConverter::setLiteralType(ScalarConverter::DOUBLE);
	}
	else
	{
		ScalarConverter::setLiteralType(ScalarConverter::INTEGER);
	}

	return ;
}
