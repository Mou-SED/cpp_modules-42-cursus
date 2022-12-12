/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:01:18 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/12 20:36:03 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int _fixed_point_value;
		static const int _fractional_bits = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & src );
		Fixed & operator=( Fixed const & other );
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif