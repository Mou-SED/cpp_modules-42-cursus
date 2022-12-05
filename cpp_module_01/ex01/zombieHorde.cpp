/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:21:23 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/05 08:42:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie *zombies = new (std::nothrow) Zombie[N];
	if (zombies == NULL)
		return (NULL);
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return (zombies);
}
