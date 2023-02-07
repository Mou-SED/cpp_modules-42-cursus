/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:33:08 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 15:08:03 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : AAnimal() , _brain(new Brain())
{
	std::cout << GREEN << "Dog default constructor is called" << RESET << std::endl;
	this->_type = std::string("Dog");
	return ;
}

Dog::Dog( Dog const & src ) : AAnimal(src), _brain(new Brain())
{
	std::cout << GREEN << "Dog copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog( void )
{
	std::cout << RED << "Dog destructor is called" << RESET << std::endl;
	delete this->_brain;
	return ;
}

Dog & Dog::operator=( Dog const & other )
{
	std::cout << GREEN << "Dog assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *other._brain;
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
