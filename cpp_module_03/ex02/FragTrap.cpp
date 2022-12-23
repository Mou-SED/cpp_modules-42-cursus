/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:27:36 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/23 17:45:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << GREEN << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap( std::string name )
{
	std::cout << GREEN << "FragTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap( FragTrap const & src)
{
	std::cout << GREEN << "FragTrap copy constructor called" << RESET << std::endl;
	*this = src;
}

FragTrap::~FragTrap( void )
{
	std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
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
}