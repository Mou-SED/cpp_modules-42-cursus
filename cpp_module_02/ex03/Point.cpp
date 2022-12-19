/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:56:30 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/19 22:39:50 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( float const & x, float const & y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point( Point const & src ) : _x(src._x), _y(src._y)
{
}

Point::~Point( void )
{
}

Point & Point::operator=( Point const & other )
{
	(void)other;
	return *this;
}

float Point::getX( void ) const
{
	return _x.toFloat();
}

float Point::getY( void ) const
{
	return _y.toFloat();
}
