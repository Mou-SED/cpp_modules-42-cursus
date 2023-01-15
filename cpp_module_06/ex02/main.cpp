/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:31:48 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 03:53:29 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base*	generate( void )
{
	int random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify( Base * p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;

	return ;
}

void	identify( Base & p )
{
    try
	{
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
	catch (std::bad_cast const & e) {}
    try
	{
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
	catch (std::bad_cast const & e) {}
    try
	{
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
	catch (std::bad_cast const & e) {}

	return ;
}

int main( void )
{
	srand(time(NULL));

	Base * base = generate();

	identify(base);
	identify(*base);

	delete base;
	return (0);
}