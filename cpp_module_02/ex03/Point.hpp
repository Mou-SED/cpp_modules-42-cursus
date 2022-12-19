/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:52:29 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/19 22:41:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point( void );
		Point( float const & x, float const & y );
		Point( Point const & src );
		~Point( void );

		Point & operator=( Point const & other );

		float getX( void ) const;
		float getY( void ) const;
};

#endif