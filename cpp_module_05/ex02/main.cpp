/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/08 20:25:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    Bureaucrat b1("Bob", 5);
    Bureaucrat b2("Alice", 40);
    Bureaucrat b3("Eve", 50);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

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

    ShrubberyCreationForm f1("Home");
    RobotomyRequestForm f2("Robot");
    PresidentialPardonForm f3("Criminal");

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    try
    {
        std::cout << "Signing form 1" << std::endl;
        f1.beSigned(b1);
        std::cout << "Signing form 2" << std::endl;
        f2.beSigned(b2);
        std::cout << "Signing form 3" << std::endl;
        f3.beSigned(b3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Signing form 1" << std::endl;
        b1.signForm(f1);
        std::cout << "Signing form 2" << std::endl;
        b2.signForm(f2);
        std::cout << "Signing form 3" << std::endl;
        b3.signForm(f3);

        std::cout << "Executing form 1" << std::endl;
        b1.executeForm(f1);
        std::cout << "Executing form 2" << std::endl;
        b2.executeForm(f2);
        std::cout << "Executing form 3" << std::endl;
        b3.executeForm(f3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}