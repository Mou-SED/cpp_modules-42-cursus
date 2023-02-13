/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:36:35 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/13 11:54:50 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
	Span sp = Span(5);

	std::vector<int> v(20, 4);
	Span sp2 = Span(20);

	try
	{
		sp2.addNumbers( v.begin(), v.end() );
		std::vector<int>::iterator itBegin = sp2.getVec().begin();
		std::vector<int>::iterator itEnd = sp2.getVec().end();
		sp2.show( itBegin, itEnd );

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(12);

		std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan  : " << sp.longestSpan() << std::endl;
	}
	catch(int const & num)
	{
		if (num == 404)
			std::cerr << RED << "Exception : You can not addNumber!" << RESET << std::endl;
		if (num == 405)
			std::cerr << RED << "Exception : There is no elements or just one!" << RESET << std::endl;
		return -1;
	}

	return 0;
}