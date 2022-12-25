/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/24 12:08:07 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragtrap("FR4P-TP");

	fragtrap.attack("target");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
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
	fragtrap2.highFivesGuys();

	return 0;
}