/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:31:46 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 18:02:26 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria(std::string("cure"))
{
	return ;
}

Cure::Cure( Cure const & src ) : AMateria(src)
{
	return ;
}

Cure::~Cure( void )
{
	return ;
}

Cure & Cure::operator=( Cure const & other )
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone( void ) const
{
	return (new Cure(*this));
}

void Cure::use( ICharacter & target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

void Cure::setType( std::string const & type )
{
	this->_type = type;
}