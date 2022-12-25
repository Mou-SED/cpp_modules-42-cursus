/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:31:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/24 21:32:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << GREEN << "DiamondTrap default constructor called" << RESET << std::endl;
	this->_name = "Default DT";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << GREEN << "DiamondTrap constructor called" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " is created" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src)
	: FragTrap(src), ScavTrap(src), _name(src._name)
{
	std::cout << GREEN << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << RED << "DiamondTrap destructor called" << RESET << std::endl;
	return ;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & other)
{
	std::cout << GREEN << "DiamondTrap assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}