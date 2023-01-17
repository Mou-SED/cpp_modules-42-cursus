/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:01:24 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/17 01:46:13 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	printStrings( std::string & x )
{
    std::cout << x << std::endl;

	return ;
}

static void	addTowInts( int & a )
{
	a = a + 2;

	return ;
}

template< typename T >
static void	printElements( T *input, size_t len )
{
    for ( int i = 0; i < len; ++i)
	{
		std::cout << input[i] << " ";
		if (i == len - 1)
			std::cout << std::endl;
	}

	return ;
}

int main( void )
{
	std::size_t		strLen = 5;
    std::string	str[strLen] = {"G1", "G2", "G3", "G4", "G5"};

	int arrLen = 6;
	int arr[arrLen] = {1, 2, 3, 4, 5, 6};

    iter( str, strLen, printStrings );
    iter( arr, arrLen, addTowInts );

	printElements( str, strLen );
	printElements( arr, arrLen );
    return 0;
}
