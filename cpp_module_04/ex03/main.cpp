/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:54:24 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/31 22:42:31 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// Main test
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}

//! test deep copy of character
// int main()
// {
//     // Create an instance of Character with name "Alice"
//     Character alice("Alice");

//     // Create a shallow copy of alice using the copy constructor
//     Character shallow_copy(alice);

//     // Create a deep copy of alice using the assignment operator
//     Character deep_copy;
//     deep_copy = alice;

//     // Modify the name of the original Character
//     alice.setName("Bob");

//     // Print the name of each Character
//     std::cout << "Original Character: " << alice.getName() << std::endl;
//     std::cout << "Shallow copy Character: " << shallow_copy.getName() << std::endl;
//     std::cout << "Deep copy Character: " << deep_copy.getName() << std::endl;

//     return 0;
// }

//! test deep copy of materiaSource
// int main()
// {
//     // Create a MateriaSource object
//     IMateriaSource* src = new MateriaSource();

//     // Learn a new Materia
//     AMateria* ice = new Ice();
//     src->learnMateria(ice);

//     // Create a copy of the Materia using the MateriaSource
//     AMateria* ice_copy = src->createMateria("ice");

//     // Modify the original Materia
//     ice->setType("fire");

//     // Print the type of the original and copy Materias
//     std::cout << "Original Materia: " << ice->getType() << std::endl;
//     if (ice_copy)
//         std::cout << "Copy Materia: " << ice_copy->getType() << std::endl;
//     else
//         std::cout << "Copy Materia: NULL" << std::endl;

//     delete ice;
//     delete ice_copy;

//     return 0;
// }

//! Simple test for Character and Materias
// int main()
// {
//     // Create a character
//     Character character("John");
//     std::cout << "Created character " << character.getName() << std::endl;

//     // Create some materias
//     AMateria *iceMateria = new Ice();
//     AMateria *cureMateria = new Cure();
//     std::cout << "Created materias " << iceMateria->getType() << " and " << cureMateria->getType() << std::endl;

//     // Equip materias
//     character.equip(iceMateria);
//     character.equip(cureMateria);
//     std::cout << "Equipped materias" << std::endl;

//     // Use materias
//     Character target("Alice");
//     character.use(0, target);
//     character.use(1, target);
//     std::cout << "Used materias on character " << target.getName() << std::endl;

//     // Unequip materias
//     character.unequip(0);
//     character.unequip(1);
//     std::cout << "Unequipped materias" << std::endl;

//     // Clean up
//     delete iceMateria;
//     delete cureMateria;

//     return 0;
// }
