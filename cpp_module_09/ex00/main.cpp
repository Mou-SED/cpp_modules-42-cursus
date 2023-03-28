/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:48:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/28 12:16:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	std::string fileName = av[1];

	checkInputFile(fileName);
	return 0;
}