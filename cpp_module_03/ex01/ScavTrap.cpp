/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:09:23 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/25 14:55:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
	: ClapTrap()
{
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
	this->_name = "Default-ST";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( std::string name )
	: ClapTrap(name)
{
	std::cout << GREEN << "ScavTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const & src)
	: ClapTrap(src)
{
	std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << RED << "ScavTrap destructor called" << RESET << std::endl;
	return ;
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

void	ScavTrap::attack( std::string const & target )
{
	if (this->_energyPoints > 0 || this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has no energy points left (hitPoints) and cannot attack!" << std::endl;
	return ;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
	return ;
}
