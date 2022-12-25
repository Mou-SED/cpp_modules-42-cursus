/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:27:36 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/25 13:24:51 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
	: ClapTrap()
{
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
	this->_name = "Default FT";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << GREEN << "FragTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap( FragTrap const & src)
	: ClapTrap(src._name)
{
	std::cout << GREEN << "FragTrap copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
	return ;
}

FragTrap & FragTrap::operator=( FragTrap const & other )
{
	std::cout << GREEN << "FragTrap assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " is giving high fives" << std::endl;
	return ;
}