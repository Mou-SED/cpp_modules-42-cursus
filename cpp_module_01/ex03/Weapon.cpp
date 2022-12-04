/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:25:16 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/03 01:37:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	std::cout << std::endl << GREEN << "Weapon constructor called" << RESET << std::endl << std::endl;
}

Weapon::~Weapon()
{
	std::cout << std::endl << RED << "Weapon destructor called" << RESET << std::endl << std::endl;
}

const std::string& Weapon::getType( void ) const
{
	return (this->_type);
}

void Weapon::setType( std::string type )
{
	this->_type = type;
}
