/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:16:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/30 13:27:55 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int ac, char **av )
{
	if (ac == 1 )
	{
		std::cout << RED << "Usage: ./PmergMe [num1] [num2] [num3] ..." << RESET << std::endl;
		return 0;
	}
	size_t size;
	size = ac - 1;
	for ( int i = 1; i < ac; i++ )
	{
		if ( strspn(av[i], "0123456789") != strlen(av[i]) )
		{
			std::cout << RED << "Error: Invalid input" << RESET << std::endl;
			return 1;
		}
	}
	PmergeMe pmergeMe( ac, av, size );

	pmergeMe.printBefore();
	pmergeMe.runVector();
	pmergeMe.runDeque();
	pmergeMe.printAfter();

	return 0;
}