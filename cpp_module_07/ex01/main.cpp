/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:01:24 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/11 14:55:30 by moseddik         ###   ########.fr       */
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
    for ( size_t i = 0; i < len; ++i)
	{
		std::cout << input[i] << " ";
		if (i == len - 1)
			std::cout << std::endl;
	}

	return ;
}

int main( void )
{
    std::string	str[5] = {"G1", "G2", "G3", "G4", "G5"};

	int arr[6] = {1, 2, 3, 4, 5, 6};

    iter( str, 5, printStrings );
    iter( arr, 6, addTowInts );

	printElements( str, 5 );
	printElements( arr, 6 );
    return 0;
}
