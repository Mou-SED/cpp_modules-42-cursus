/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:31:52 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:36 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << "Invalid arguments!" << std::endl;
		return 1;
	}
	std::string input = av[1];

	input = removeSpaces( input );

	if ( check_format( input ) == false )
	{
		std::cout << "Error : RPN Format is invalid!" << std::endl;
		return 1;
	}

	std::cout << "Result: " << calculate( input ) << std::endl;
	return 0;
}