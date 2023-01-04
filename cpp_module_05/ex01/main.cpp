/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/04 22:40:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main( void )
{
	Bureaucrat	b1( "Bureaucrat-v1", 51 );
	Form		f1( "Form-v1", 50, 100 );
	Form		f2( "Form-v2", 10, 120 );

	f1.beSigned( b1 );
	std::cout << f1 << std::endl;
	std::cout << std::endl;

	b1.incrementGrade();
	std::cout << GREEN << "After increment Grade of Bureaucrat-v1 by 1" << RESET << std::endl;
	f1.beSigned( b1 );
	std::cout << f1 << std::endl;

	std::cout << std::endl;
	std::cout << "Test copy assignment" << std::endl;
	f2 = f1;
	std::cout << "About f2: " << f2 << std::endl;
	return 0;
}