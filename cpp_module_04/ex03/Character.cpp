/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:01:20 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 16:10:44 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	return ;
}

Character::Character( std::string const & name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	return ;
}

Character::Character( Character const & src ) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	return ;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
	}
	return ;
}

Character & Character::operator=( Character const & other )
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = nullptr;
			}
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = nullptr;
		}
	}
	return (*this);
}

std::string const & Character::getName( void ) const
{
	return (this->_name);
}

void Character::equip( AMateria * m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m->clone();
			break ;
		}
	}
	return ;
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = nullptr;
	}
	return ;
}

void Character::use( int idx, ICharacter & target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	return ;
}

void Character::setName( std::string const & name )
{
	this->_name = name;
	return ;
}
