/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:50:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/14 12:42:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert( void )
	: _literalType(UNKNOWN)
{
	return ;
}

Convert::Convert( Convert const & src )
	: _literalType(src.getLiteralType())
{
	return ;
}

Convert::~Convert( void )
{
	return ;
}

Convert &	Convert::operator=( Convert const & other )
{
	this->_literalType = other.getLiteralType();
	return (*this);
}

void		Convert::setLiteralType( LiteralType type )
{
	_literalType = type;
	return ;
}

Convert::LiteralType	Convert::getLiteralType( void ) const
{
	return (this->_literalType);
}

void	Convert::parsing( std::string const & input )
{
	if (input.size() == 1)
		this->setLiteralType(Convert::CHAR);
	else if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nan" || input == "nanf")
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
			this->setLiteralType(Convert::FLOAT);
		else
			this->setLiteralType(Convert::DOUBLE);
	}
	else
	{
		this->setLiteralType(Convert::INTEGER);
	}

	return ;
}
