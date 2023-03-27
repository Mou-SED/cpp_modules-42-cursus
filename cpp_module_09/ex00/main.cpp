/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:48:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/27 14:44:37 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isValidValue( std::string value )
{
	std::string line = value;
	value = value.substr(value.find("|") + 1);
	bool isDot = false;
	for ( size_t i = 0; i < value.size(); i++ )
	{
		if ( value[i] == '.' )
		{
			if ( isDot )
				return false;
			isDot = true;
		}
		else if ( (value[i] < '0' || value[i] > '9') and value[i] != '-' )
		{
			std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
			return false;
		}
	}
	std::stringstream ss(value);
	double dValue = 0.0;
	ss >> dValue;
	if ( dValue > 1000.0 )
	{
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return false;
	}
	if (  dValue < 0.0 )
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	return true;
}

bool	check_format( std::string & line )
{
	std::string out = "";
	for ( size_t i = 0; i < line.size(); ++i )
	{
		if ( line[i] != ' ' and line[i] != '\t' )
			out.push_back(line[i]);
	}
	line = out;
	if ( line.find("|") == std::string::npos )
	{
		std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
		return false;
	}
	if ( line.find("-") == std::string::npos or line.find("-", line.find("-") + 1) == std::string::npos )
	{
		std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
		return false;
	}
	if ( !isValidValue(line) )
		return false;
	return true;
}

bool	isValidDate( std::string date )
{
	bool formatValid = true;
	std::string year = "";
	std::string month = "";
	std::string day = "";
	int yearValue = 0;
	int monthValue = 0;
	int dayValue = 0;

	date = date.substr(0, date.find("|"));

	year = date.substr(0, date.find("-"));
	std::stringstream ss(year);
	ss >> yearValue;
	month = date.substr(date.find("-") + 1, date.find("-", date.find("-") + 1));
	std::stringstream ss2(month);
	ss2 >> monthValue;
	day = date.substr(date.find("-", date.find("-") + 1) + 1);
	std::stringstream ss3(day);
	ss3 >> dayValue;

	if ( yearValue < 1970 || yearValue > 2038 )
		formatValid = false;
	if ( monthValue < 1 || monthValue > 12 )
		formatValid = false;
	if ( dayValue < 1 || dayValue > 31 )
		formatValid = false;
	if ( monthValue == 2 and yearValue % 4 == 0 and dayValue > 29 )
		formatValid = false;
	else if (monthValue == 2 and yearValue % 4 != 0 and dayValue > 28)
		formatValid = false;
	if ( (monthValue == 9 or monthValue == 4 or monthValue == 6 or monthValue == 11) and dayValue == 31 )
		formatValid = false;
	if ( !formatValid )
	{
		std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
		return false;
	}
	return true;
}

void checkInputFile( std::string fileName )
{
	std::string line = "";
	std::ofstream fileOut;
	std::ifstream fileInput;

	fileInput.open( fileName, std::ios::in );
	if ( !fileInput.is_open() )
	{
		std::cout << RED << "Error: could not open file." << std::endl;
		exit(1);
	}
	while ( std::getline(fileInput, line) )
	{
		if ( line.empty() || line[0] == '#' || line[0] == ' ' || line[0] == '\t' || line == "date | value" )
			continue;
		if ( !check_format(line) or !isValidDate(line))
			continue;
		std::cout << line << std::endl;
	}
	fileInput.close();

	return ;
}


int main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	BitcoinExchange bitcoinExchange("data.csv");

	std::string fileName = av[1];

	try
	{
		checkInputFile(fileName);
	}
	catch (std::invalid_argument & e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// try
	// {
	// 	std::cout << bitcoinExchange.getExchangeRate("2011-01-03") << std::endl;
	// }
	// catch (std::invalid_argument & e)
	// {
	// 	std::cerr << RED << e.what() << RESET << std::endl;
	// }
	return 0;
}