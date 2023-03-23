/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:34 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/23 16:19:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( std::string const & fileName )
{
	std::ifstream fileInput;
	std::string line = "";
	std::string date = "";
	std::string rate = "";
	double rateValue = 0.0;

	fileInput.open( fileName, std::ios::in );
	if ( !fileInput.is_open() )
	{
		std::cerr << RED << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::getline(fileInput, line); // Skip First Line
	while ( std::getline(fileInput, line) )
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, rate, ',');
		std::stringstream ss2(rate);
		rateValue = ss2 >> rateValue ? rateValue : 0.0;
		_rates[date] = rateValue;
	}
	fileInput.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

double	BitcoinExchange::getExchangeRate(std::string const & date) const
{
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it == _rates.end())
		throw std::invalid_argument("Error: date not found.");
	return it->second;
}