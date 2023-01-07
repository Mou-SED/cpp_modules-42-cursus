/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 23:41:43 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern someRandomIntern;

    AForm* form = nullptr;
    try
    {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        try
        {
            Bureaucrat b1("Bob", 5);
            try
            {
                std::cout << b1 << std::endl;
                form->beSigned(b1);
                std::cout << *form << std::endl;
                b1.executeForm(*form);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            delete form;
            return 1;
        }
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
	return 0;
}