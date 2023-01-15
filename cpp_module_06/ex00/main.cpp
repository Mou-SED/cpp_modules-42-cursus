/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:30 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/14 23:12:04 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main( int ac, char ** av )
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./main <string>" << std::endl;
		return 1;
	}
	std::string input = av[1];
	if (input.length() == 0)
	{
		std::cerr << "String is empty" << std::endl;
		return 1;
	}

	Convert conv;

	conv.parsing(input);

	// Print the type of the input
    switch (conv.getLiteralType())
	{
        case (Convert::CHAR):
			conv.convChar( input );
            break;
        case (Convert::INTEGER):
			conv.convInt( input );
            break;
        case (Convert::FLOAT):
			conv.convFloat( input );
            break;
        case (Convert::DOUBLE):
			conv.convDouble( input );
            break;
		default:
		{
			std::cout << "Unknown" << std::endl;
			break ;
		}
    }
	return 0;
}