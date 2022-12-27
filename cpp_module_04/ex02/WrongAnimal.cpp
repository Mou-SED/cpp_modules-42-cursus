/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:29:15 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:45:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
	return ;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & other )
{
	std::cout << GREEN << "WrongAnimal assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	WrongAnimal::makeSound( void )
{
	std::cout << "WrongAnimal makeSound called" << std::endl;
	return ;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound called" << std::endl;
	return ;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}
