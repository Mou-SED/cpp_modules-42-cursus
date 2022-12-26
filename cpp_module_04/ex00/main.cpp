/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:34:41 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:51:53 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	meta = nullptr;
	j = nullptr;
	i = nullptr;

	return 0;
}

// ? WrongAnimal test

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main( void )
// {
// 	const WrongAnimal* wrong_animal = new WrongAnimal();
// 	const WrongAnimal* wrong_cat = new WrongCat();

// 	std::cout << wrong_animal->getType() << " " << std::endl;
// 	std::cout << wrong_cat->getType() << " " << std::endl;

// 	wrong_animal->makeSound();
// 	wrong_cat->makeSound();

// 	delete wrong_animal;
// 	delete wrong_cat;

// 	wrong_animal = nullptr;
// 	wrong_cat = nullptr;

// 	return 0;
// }
