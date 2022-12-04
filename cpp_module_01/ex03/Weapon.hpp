/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:51:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/03 01:36:18 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon( std::string type );
		~Weapon();
		const std::string& getType( void ) const;
		void setType( std::string type );
	private:
		std::string _type;
};

#endif