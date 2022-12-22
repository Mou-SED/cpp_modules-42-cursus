/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:52:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/22 15:18:35 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	std::cout << "------------------------" << std::endl;
	ClapTrap claptrap2(claptrap);
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");
	claptrap2.attack("target");

	claptrap2.takeDamage(5);
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);

	return 0;
}