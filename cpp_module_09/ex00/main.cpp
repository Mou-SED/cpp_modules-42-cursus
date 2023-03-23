/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:48:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/23 14:27:28 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// bool	check_format()
// {}

// bool	isValidDate()
// {}

// bool	isValidValue()
// {}

int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	BitcoinExchange bitcoinExchange("data.csv");

	std::string fileName = av[1];
	std::string line = "";
	std::ofstream fileOut;
	std::ifstream fileInput;

	fileInput.open( fileName, std::ios::in );
	if ( !fileInput.is_open() )
	{
		std::cerr << RED << "Error: could not open file." << std::endl;
		exit(1);
	}
	while ( std::getline(fileInput, line) )
	{
		std::cout << line << std::endl;
	}
	fileInput.close();
	try
	{
		std::cout << bitcoinExchange.getExchangeRate("date") << std::endl;
	}
	catch (std::invalid_argument & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}