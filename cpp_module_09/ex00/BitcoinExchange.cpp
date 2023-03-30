/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:34 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/30 14:05:42 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _rates()
{
	return ;
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
		std::cout << RED << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::getline(fileInput, line); // Skip First Line
	if ( fileInput.peek() == std::ifstream::traits_type::eof() )
	{
		std::cout << RED << "Error: Data File is empty." << std::endl;
		exit(1);
	}
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

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src ) : _rates(src._rates)
{
	return ;
}

BitcoinExchange::~BitcoinExchange()
{
	_rates.clear();
	return ;
}

BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & other )
{
	if ( this != &other )
	{
		_rates = other._rates;
	}
	return *this;
}

double	BitcoinExchange::getExchangeRate(std::string const & date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
	if (it->first != date and it != _rates.begin())
		--it;
	return it->second;
}

// Parse Input File and Check if it's Valid

bool	isValidValue( std::string value )
{
	std::string line = value;
	value = value.substr(value.find("|") + 1);
	if ( value.size() == 0 )
	{
		std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
		return false;
	}
	bool isDot = false;
	size_t i = 0;

	if ( value[0] == '-' )
		i++;
	while ( i < value.size() )
	{
		if ( value[i] == '.' )
		{
			if ( isDot )
			{
				std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
				return false;
			}
			isDot = true;
		}
		else if ( (value[i] < '0' || value[i] > '9') )
		{
			std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
			return false;
		}
		i++;
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

double	getValue( std::string value )
{
	std::string line = value;
	value = value.substr(value.find("|") + 1);
	std::stringstream ss(value);
	double dValue = 0.0;
	ss >> dValue;

	return dValue;
}

bool	checkFormat( std::string line )
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
	std::string line = date;
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
		std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
		return false;
	}
	return true;
}

void checkInputFile( std::string fileName )
{
	std::string line = "";
	std::ofstream fileOut;
	std::ifstream fileInput;
	BitcoinExchange bitcoinExchange("data.csv");

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
		if ( !checkFormat(line) or !isValidDate(line))
			continue;
		std::cout << line.substr(0, line.find("|"))
			<< " => " << line.substr(line.find("|") + 1) << " = "
			<< bitcoinExchange.getExchangeRate(line.substr(0, line.find("|"))) * getValue(line) << std::endl;
	}
	fileInput.close();

	return ;
}