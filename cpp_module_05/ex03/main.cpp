/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 14:40:25 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	// Create some bureaucrat objects
    Bureaucrat b1("Bob", 5);
    Bureaucrat b2("Alice", 40);
    Bureaucrat b3("Eve", 50);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    // Try to increment and decrement the grades of the bureaucrats
    try
    {
        b1.incrementGrade();
        b2.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    // Create some form objects
    ShrubberyCreationForm f1("Home");
    RobotomyRequestForm f2("Robot");
    PresidentialPardonForm f3("Criminal");

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

	// Try to sign the forms
	try
	{
		f1.beSigned(b1);
		f2.beSigned(b2);
		f3.beSigned(b3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    // Try to sign and execute the forms
    try
    {
        b1.signForm(f1);
        b2.signForm(f2);
        b3.signForm(f3);

        b1.executeForm(f1);
        b2.executeForm(f2);
        b3.executeForm(f3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	return 0;
}