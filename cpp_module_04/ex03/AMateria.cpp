/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:33:17 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/29 19:38:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type(std::string("default"))
{
	return ;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	return ;
}

AMateria::AMateria( AMateria const & src ) : _type(src._type)
{
	return ;
}

AMateria::~AMateria( void )
{
	return ;
}

AMateria & AMateria::operator=( AMateria const & other )
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}

void AMateria::use( ICharacter & target )
{
	(void)target;
	return ;
}
