/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:09:23 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/23 17:08:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap( std::string name )
{
	std::cout << GREEN << "ScavTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap const & src)
{
	std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << RED << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & other )
{
	std::cout << GREEN << "ScavTrap assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}
