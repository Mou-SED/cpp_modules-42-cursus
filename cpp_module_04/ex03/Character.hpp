/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:46:38 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/31 22:26:49 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];

	public:
		Character( void );
		Character( std::string const & name );
		Character( Character const & src );
		~Character( void );

		Character & operator=( Character const & other );

		std::string const & getName( void ) const;
		void equip( AMateria *m );
		void unequip( int idx );
		void use( int idx, ICharacter & target );

		void setName( std::string const & name ); // TODO: remove this
};

#endif