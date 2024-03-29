/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:36:24 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 16:11:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class AMateria;
# include "AMateria.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter( void ) {}
		virtual std::string const & getName( void ) const = 0;
		virtual void equip( AMateria *m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter & target ) = 0;
		virtual void setName( std::string const & name ) = 0;
};

#endif