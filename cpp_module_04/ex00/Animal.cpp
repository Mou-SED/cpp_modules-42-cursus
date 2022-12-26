/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 16:06:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << GREEN << "Animal default constructor is called" << RESET << std::endl;
	return ;
}

Animal::Animal( Animal const & src )
{
	std::cout << GREEN << "Animal copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

Animal::~Animal( void )
{
	std::cout << RED << "Animal destructor is called" << RESET << std::endl;
	return ;
}

Animal & Animal::operator=( Animal const & other )
{
	std::cout << GREEN << "Animal assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	Animal::makeSound( void )
{
	std::cout << "The animal make sound" << std::endl;
	return ;
}

void	Animal::makeSound( void ) const
{
	std::cout << "The animal make sound" << std::endl;
	return ;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}
