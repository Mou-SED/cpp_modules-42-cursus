/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:12:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 00:09:18 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
	std::cout << GREEN << "AAnimal default constructor is called" << RESET << std::endl;
	return ;
}

AAnimal::AAnimal( AAnimal const & src )
{
	std::cout << GREEN << "AAnimal copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

AAnimal::~AAnimal( void )
{
	std::cout << RED << "AAnimal destructor is called" << RESET << std::endl;
	return ;
}

AAnimal & AAnimal::operator=( AAnimal const & other )
{
	std::cout << GREEN << "AAnimal assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}