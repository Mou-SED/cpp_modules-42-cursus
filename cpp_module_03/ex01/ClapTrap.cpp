/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:06:02 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/25 12:41:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
	: _name("Default-CT"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "ClapTrap default constructor called" << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name )
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREEN << "ClapTrap constructor called" << RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src)
{
	std::cout << GREEN << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & other)
{
	std::cout << GREEN << "ClapTrap assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack( std::string const & target )
{
	if (this->_energyPoints > 0 || this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left (hitPoints) and cannot attack!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage and has " << this->_hitPoints << " hit points left" << std::endl;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints > 0 || this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " points and has " << this->_hitPoints << " hit points" << std::endl;
	} else
		std::cout << "ClapTrap " << this->_name << " has no energy points left (hitPoints) and cannot repair itself!" << std::endl;
	return ;
}

std::string ClapTrap::getName( void ) const
{
	return (this->_name);
}