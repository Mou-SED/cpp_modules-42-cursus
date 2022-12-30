/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:54:24 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/29 23:47:34 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>
#include <string>

int main()
{
    // Create a character
    Character character("John");
    std::cout << "Created character " << character.getName() << std::endl;

    // Create some materias
    AMateria *iceMateria = new Ice();
    AMateria *cureMateria = new Cure();
    std::cout << "Created materias " << iceMateria->getType() << " and " << cureMateria->getType() << std::endl;

    // Equip materias
    character.equip(iceMateria);
    character.equip(cureMateria);
    std::cout << "Equipped materias" << std::endl;

    // Use materias
    Character target("Alice");
    character.use(0, target);
    character.use(1, target);
    std::cout << "Used materias on character " << target.getName() << std::endl;

    // Unequip materias
    character.unequip(0);
    character.unequip(1);
    std::cout << "Unequipped materias" << std::endl;

    // Clean up
    delete iceMateria;
    delete cureMateria;

    return 0;
}
