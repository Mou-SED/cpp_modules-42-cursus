/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:37:41 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:42:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << GREEN << "Cat default constructor is called" << RESET << std::endl;
	this->_type = std::string("Cat");
	return ;
}

Cat::Cat( Cat const & src ) : Animal(src)
{
	std::cout << GREEN << "Cat copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

Cat::~Cat( void )
{
	std::cout << RED << "Cat destructor is called" << RESET << std::endl;
	return ;
}

Cat & Cat::operator=( Cat const & other )
{
	std::cout << GREEN << "Cat assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound( void )
{
	std::cout << "myaw myaw!" << std::endl;
	return ;
}

void	Cat::makeSound( void ) const
{
	std::cout << "myaw myaw!" << std::endl;
	return ;
}