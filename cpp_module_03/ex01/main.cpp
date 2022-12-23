/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/23 17:12:43 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavtrap("CL4P-TP");

	scavtrap.attack("target");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();

	std::cout << "------------------------" << std::endl;
	ScavTrap scavtrap2(scavtrap);
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");
	scavtrap2.attack("target");

	scavtrap2.takeDamage(5);
	scavtrap2.takeDamage(5);
	scavtrap2.beRepaired(3);
	scavtrap2.guardGate();

	return 0;
}