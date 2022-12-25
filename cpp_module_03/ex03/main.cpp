/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/24 16:19:20 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dimondTrap("DT4P-TP");

	dimondTrap.attack("target");
	dimondTrap.takeDamage(5);
	dimondTrap.beRepaired(3);
	dimondTrap.guardGate();
	dimondTrap.highFivesGuys();

	std::cout << "------------------------" << std::endl;
	DiamondTrap dimondTrap2(dimondTrap);
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");
	dimondTrap2.attack("target");

	dimondTrap2.takeDamage(5);
	dimondTrap2.takeDamage(5);
	dimondTrap2.beRepaired(3);
	dimondTrap2.guardGate();
	dimondTrap2.highFivesGuys();

	return 0;
}