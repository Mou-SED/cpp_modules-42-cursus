/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:58:29 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 12:23:48 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << GREEN << "Brain default constructor is called" << RESET << std::endl;
	for ( int i = 0; i < 100; i++ )
		this->_ideas[i] = "";
	return ;
}

Brain::Brain( Brain const & src )
{
	std::cout << GREEN << "Brain copy constructor is called" << RESET << std::endl;
	*this = src;
	return ;
}

Brain::~Brain( void )
{
	std::cout << RED << "Brain destructor is called" << RESET << std::endl;
	return ;
}

Brain & Brain::operator=( Brain const & other )
{
	std::cout << GREEN << "Brain assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		for ( int i = 0; i < 100; i++ )
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}