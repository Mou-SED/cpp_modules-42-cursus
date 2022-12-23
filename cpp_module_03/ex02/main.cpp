/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/23 17:48:25 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragtrap("FR4P-TP");

	fragtrap.attack("target");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
	fragtrap.guardGate();
	fragtrap.highFivesGuys();

	std::cout << "------------------------" << std::endl;
	FragTrap fragtrap2(fragtrap);
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");
	fragtrap2.attack("target");

	fragtrap2.takeDamage(5);
	fragtrap2.takeDamage(5);
	fragtrap2.beRepaired(3);
	fragtrap2.guardGate();
	fragtrap2.highFivesGuys();

	return 0;
}