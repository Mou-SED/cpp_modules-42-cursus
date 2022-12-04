/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:39:28 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/03 18:59:52 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie* zombie = newZombie("moussa");
	if (zombie == NULL)
		std::cout << "Allocation failed" << std::endl;
	else
	{
		zombie->announce();
		delete zombie;
	}
	std::cout << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	randomChump("seddik");
	return (EXIT_SUCCESS);
}