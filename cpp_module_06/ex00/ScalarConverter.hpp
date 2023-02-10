/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:39:23 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/14 12:44:06 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <sstream>
#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter( void );

		ScalarConverter &	operator=( ScalarConverter const & other );

		enum LiteralType {
			INTEGER,
			FLOAT,
			DOUBLE,
			CHAR,
			UNKNOWN
		};

		static void		setLiteralType( LiteralType type );
		static LiteralType	getLiteralType( void );

		static void		convert( std::string & input );
		static void		convChar( std::string const & input );
		static void		convInt( std::string const & input );
		static void		convFloat( std::string & input );
		static void		convDouble( std::string const & input );

	private:
		static LiteralType	_literalType;

};

bool	check_input( std::string &str );
void	parsing( std::string const & input );

#endif
