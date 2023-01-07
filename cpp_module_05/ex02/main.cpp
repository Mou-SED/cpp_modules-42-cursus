/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 14:02:48 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	Bureaucrat bureaucrat("Bureaucrat", 5);

	ShrubberyCreationForm form("ShrubberyCreationForm");
	RobotomyRequestForm form2("RobotomyRequestForm");
	PresidentialPardonForm form3("PresidentialPardonForm");

	form.beSigned(bureaucrat);
	form2.beSigned(bureaucrat);
	form3.beSigned(bureaucrat);

	std::cout << form << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	bureaucrat.signForm(form);
	bureaucrat.signForm(form2);
	bureaucrat.signForm(form3);

	form.execute(bureaucrat);
	form2.execute(bureaucrat);
	form3.execute(bureaucrat);

	std::cout << "---------------------" << std::endl;
	Bureaucrat bureaucrat2("Bureaucrat2", 20);

	RobotomyRequestForm form4("RobotomyRequestForm2");
	PresidentialPardonForm form5("PresidentialPardonForm2");

	form4.beSigned(bureaucrat2);
	form5.beSigned(bureaucrat2);

	std::cout << form4 << std::endl;
	std::cout << form5 << std::endl;

	bureaucrat2.signForm(form4);
	bureaucrat2.signForm(form5);

	bureaucrat2.executeForm(form4);
	bureaucrat2.executeForm(form5);
	return 0;
}