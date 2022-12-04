/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:39:28 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/01 04:54:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie *zombies = zombieHorde(4, "moseddik");
	if (zombies == NULL)
		std::cout << "Allocation failed" << std::endl;
	else
	{
		for (int i = 0; i < 4; i++)
			zombies[i].announce();
		delete [] zombies;
	}
	return (EXIT_SUCCESS);
}