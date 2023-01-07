/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 16:09:27 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main( void )
{
	// Create bureaucrat object
	try
	{
		Bureaucrat b("Bob", 5);
		std::cout << b << std::endl;
		// Try to increment and decrement the grade of the bureaucrat
		try
		{
			b.incrementGrade();
			b.incrementGrade();
			b.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << b << std::endl;

		// Create form object
		Form f("Form", 5, 10);

		std::cout << f << std::endl;

		// Try to sign the form
		try
		{
			f.beSigned(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Try to sign and execute the form
		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		std::cerr << RED
			<< "You Have to create bureaucrat with Grade from 1 to 150" << RESET << std::endl;
		return 1;
	}

	return 0;
}