/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:49:06 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/23 13:33:42 by moseddik         ###   ########.fr       */
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

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange( std::string const & fileName );
		// BitcoinExchange( const BitcoinExchange & src );
		~BitcoinExchange();

		// BitcoinExchange & operator=( const BitcoinExchange & other );

		double	getExchangeRate(std::string const & date) const;

		// void	addCurrency( std::string const &currency, double rate );
		// void	removeCurrency( std::string const &currency );
		// void	updateRate( std::string const &currency, double rate );
		// double	convert( std::string const &from, std::string const &to, double amount );
		// void	saveToFile( std::string const &filename );
		// void	loadFromFile( std::string const &filename );

	private:
		std::map<std::string, double> _rates;
};

#endif