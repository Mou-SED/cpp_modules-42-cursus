/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:58:58 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/20 15:05:37 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main( void )
{
	float	aX, bX, cX, pX;
	float	aY, bY, cY, pY;

	std::cout << CYAN << "Enter the (x, y) coordinate of A, B, C, P respectively." << RESET;
	std::cout << std::endl;
	std::cout << YELLOW << "(xa, ya)" << RESET << std::endl;
	std::cin >> aX >> aY;
	std::cout << YELLOW << "(xb, yb)" << RESET << std::endl;
	std::cin >> bX >> bY;
	std::cout << YELLOW << "(xc, yc)" << RESET << std::endl;
	std::cin >> cX >> cY;
	std::cout << YELLOW << "(xp, yp)" << RESET << std::endl;
	std::cin >> pX >> pY;

	Point	a(aX, aY);
	Point	b(bX, bY);
	Point	c(cX, cY);
	Point	p(pX, pY);

	if (bsp(a, b, c, p) == true)
	{
		std::cout << GREEN << "The Point P is inside the triangle" << RESET;
		std::cout << std::endl;
	}
	else
	{
		std::cout << RED << "The Point P is outside the triangle" << RESET;
		std::cout << std::endl;
	}
	return 0;
}
