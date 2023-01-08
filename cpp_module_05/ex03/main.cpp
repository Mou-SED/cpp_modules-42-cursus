/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 20:17:54 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/08 20:17:58 by moseddik         ###   ########.fr       */
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
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }
    try
    {
        Bureaucrat b1("Bob", 5);
        try
        {
            b1.signForm(*form);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
        std::cout << *form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
        return 1;
    }
    delete form;
    return 0;
}