/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:31:52 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 20:42:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cerr << RED << "Invalid arguments!" << RESET << std::endl;
		return 1;
	}
	std::string input = av[1];

	input = removeSpaces( input );

	if ( check_format( input ) == false )
	{
		std::cerr << RED << "Error : RPN Format is invalid!" << RESET << std::endl;
		return 1;
	}

	try
	{
		std::cout << "Result: " << GREEN << calculate( input ) << RESET << std::endl;
	}
	catch( int const & num )
	{
		if ( num == 404 )
			std::cerr << RED << "Exception : You can not Divide by zero!" << RESET << std::endl;
	}
	return 0;
}