/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:27:51 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/29 19:59:21 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria( void );

		AMateria & operator=( AMateria const & other );

		std::string const & getType( void ) const; // Returns the Materia type

		virtual AMateria *clone( void ) const = 0;
		virtual void use( ICharacter & target );
};

#endif