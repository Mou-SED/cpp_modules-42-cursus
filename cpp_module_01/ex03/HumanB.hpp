/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 01:27:53 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/03 01:34:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		~HumanB();
		void attack( void ) const;
		void setWeapon( Weapon& weapon );
	private:
		std::string _name;
		Weapon* _weapon;
};

#endif