/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:39:23 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/14 12:44:06 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Convert_HPP
# define Convert_HPP

#include <sstream>
#include <iostream>
#include <string>

class Convert
{
	public:
		Convert( void );
		Convert( Convert const & src );
		~Convert( void );

		Convert &	operator=( Convert const & other );

		enum LiteralType {
			INTEGER,
			FLOAT,
			DOUBLE,
			CHAR,
			UNKNOWN
		};

		void		setLiteralType(LiteralType type);
		LiteralType	getLiteralType( void ) const;

		void		parsing( std::string const & input );
		void		convChar( std::string const & input );
		void		convInt( std::string const & input );
		void		convFloat( std::string & input );
		void		convDouble( std::string const & input );

	private:
		LiteralType	_literalType;

};

#endif
