/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:20:16 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/30 18:59:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( Ice const & src );
		~Ice( void );

		Ice & operator=( Ice const & other );

		AMateria *clone( void ) const;
		void use( ICharacter & target );

		void setType( std::string const & type ); // TODO: remove this
};

#endif