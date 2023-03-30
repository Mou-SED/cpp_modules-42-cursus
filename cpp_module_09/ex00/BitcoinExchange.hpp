/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:49:06 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/30 14:27:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

# include <string>
# include <map>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <iostream>
#include <iomanip>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( std::string const & fileName );
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange & operator=( const BitcoinExchange & other );

		double	getExchangeRate(std::string const & date) const;

	private:
		std::map<std::string, double> _rates;
};

bool	isValidValue( std::string value );
bool	checkFormat( std::string line );
bool	isValidDate( std::string date );
double	getValue( std::string value );
void	checkInputFile( std::string fileName );

#endif