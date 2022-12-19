/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:01:59 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/19 22:32:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float absf( float const & x )
{
	return (x < 0) ? -x : x;
}

float claculate_area( Point const & a, Point const & b, Point const & c )
{
	float const area = absf( (a.getX() * (b.getY() - c.getY())
							+ b.getX() * (c.getY() - a.getY())
							+ c.getX() * (a.getY() - b.getY()))) / 2.0f;
	return area;
}


bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	float const area = claculate_area(a, b, c);
	float const area1 = claculate_area(a, b, point);
	float const area2 = claculate_area(a, c, point);
	float const area3 = claculate_area(b, c, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	else
		return (area == area1 + area2 + area3);
}
