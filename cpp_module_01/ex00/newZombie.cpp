/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:44:39 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/05 08:41:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie* zombie = new (std::nothrow) Zombie();
	if (zombie == NULL)
		return (NULL);
	zombie->set_name(name);
	return (zombie);
}
