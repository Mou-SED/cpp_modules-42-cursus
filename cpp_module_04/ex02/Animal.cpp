/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 00:09:18 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

A_Animal::A_Animal( void )
{
	std::cout << GREEN << "A_Animal default constructor is called" << RESET << std::endl;
	return ;
}

A_Animal::A_Animal( A_Animal const & src )
{
	std::cout << GREEN << "A_Animal copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

A_Animal::~A_Animal( void )
{
	std::cout << RED << "A_Animal destructor is called" << RESET << std::endl;
	return ;
}

A_Animal & A_Animal::operator=( A_Animal const & other )
{
	std::cout << GREEN << "A_Animal assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	A_Animal::getType( void ) const
{
	return (this->_type);
}