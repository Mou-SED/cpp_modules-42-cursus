/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:01:18 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/17 12:24:34 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		Fixed & operator=( Fixed const & other );
		~Fixed( void );

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>( Fixed const & other ) const;
		bool operator<( Fixed const & other ) const;
		bool operator>=( Fixed const & other ) const;
		bool operator<=( Fixed const & other ) const;
		bool operator==( Fixed const & other ) const;
		bool operator!=( Fixed const & other ) const;

		Fixed operator+( Fixed const & other ) const;
		Fixed operator-( Fixed const & other ) const;
		Fixed operator*( Fixed const & other ) const;
		Fixed operator/( Fixed const & other ) const;

		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );

		static Fixed & min( Fixed & a, Fixed & b );
		static Fixed const & min( Fixed const & a, Fixed const & b );
		static Fixed & max( Fixed & a, Fixed & b );
		static Fixed const & max( Fixed const & a, Fixed const & b );
};

std::ostream & operator<<( std::ostream & o, Fixed const & other );

#endif