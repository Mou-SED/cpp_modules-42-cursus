/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/04 03:11:49 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat b1( "Bureaucrat-v1", 2 );

	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	b1.incrementGrade();
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	return 0;
}