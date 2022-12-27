/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:34:41 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 16:07:19 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void )
{
	A_Animal **animals = new(std::nothrow) A_Animal*[4];
	if (animals == NULL)
	{
		std::cout << "Allocation failed" << std::endl;
		return 1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Dog();
			animals[i]->makeSound();
		}
		else
		{
			animals[i] = new Cat();
			animals[i]->makeSound();
		}
	}
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	delete [] animals;
	return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;
// 	return 0;
// }


// int main()
// {
// 	Dog dog1;
// 	Dog dog2;

// 	dog1 = dog2;

// 	dog1.makeSound();
// 	return 0;
// }

// int main()
// {
// 	A_Animal animal; // abstract class can't be instantiated
// 	return 0;
// }