/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:31:56 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:41:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( WrongCat const & src ) : WrongAnimal(src)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
	return ;
}

WrongCat & WrongCat::operator=( WrongCat const & other )
{
	std::cout << GREEN << "WrongCat assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void	WrongCat::makeSound( void )
{
	std::cout << "WrongCat makeSound called" << std::endl;
	return ;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat makeSound called" << std::endl;
	return ;
}
