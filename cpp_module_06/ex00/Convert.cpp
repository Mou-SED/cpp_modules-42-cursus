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

static bool isValidDouble( std::string const & input )
{
    bool hasDot = false;
    for (char c : input) {
        if (c == '.')
		{
            if (hasDot)
                return false;
            else
                hasDot = true;
        }
		else if (!(c >= '0' && c <= '9') && !(c == '+' || c == '-'))
            return false;
    }
    return true;
}

static bool isValidFloat( std::string const & input )
{
    bool hasDot = false;
    for (char c : input)
	{
        if (c == '.')
		{
            if (hasDot)
                return false;
            else
                hasDot = true;
        }
		else if (!(c >= '0' && c <= '9')
					&& !(c == '+' || c == '-') && !(input.back() == 'f'))
            return false;
    }
    return true;
}

void	Convert::parsing( std::string const & input )
{
	if (input.length() == 1 && !(input.front() <= '9' && input.front() >= '0'))
		this->setLiteralType(Convert::CHAR);
	else if ((input.find("+inff") != std::string::npos || input.find("-inff") != std::string::npos)
			&& input.length() == 5)
		this->setLiteralType(Convert::FLOAT);
	else if ((input.find("+inf") != std::string::npos || input.find("-inf") != std::string::npos)
			&& input.length() == 4)
		this->setLiteralType(Convert::DOUBLE);
	else if (input.find("nan") != std::string::npos && input.length() == 3)
		this->setLiteralType(Convert::DOUBLE);
	else if (input.find("nanf") != std::string::npos && input.length() == 4)
		this->setLiteralType(Convert::FLOAT);
	else if (isValidDouble(input))
		this->setLiteralType(Convert::DOUBLE);
	else if (isValidFloat(input))
		this->setLiteralType(Convert::FLOAT);
	else
		this->setLiteralType(Convert::INTEGER);

	return ;
}
