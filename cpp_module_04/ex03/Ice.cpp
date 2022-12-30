/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:59 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/30 18:59:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria(std::string("ice"))
{
	return ;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
	return ;
}

Ice::~Ice( void )
{
	return ;
}

Ice & Ice::operator=( Ice const & other )
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Ice::clone( void ) const
{
	return (new Ice(*this));
}

void Ice::use( ICharacter & target )
{
	if (&target)
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

void Ice::setType( std::string const & type ) // TODO: remove this
{
	this->_type = type;
}