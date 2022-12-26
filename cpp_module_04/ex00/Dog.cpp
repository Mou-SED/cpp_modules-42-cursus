/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:33:08 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:42:45 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << GREEN << "Dog default constructor is called" << RESET << std::endl;
	this->_type = std::string("Dog");
	return ;
}

Dog::Dog( Dog const & src ) : Animal(src)
{
	std::cout << GREEN << "Dog copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog( void )
{
	std::cout << RED << "Dog destructor is called" << RESET << std::endl;
	return ;
}

Dog & Dog::operator=( Dog const & other )
{
	std::cout << GREEN << "Dog assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound( void )
{
	std::cout << "aow aow!" << std::endl;
	return ;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wow aow!" << std::endl;
	return ;
}