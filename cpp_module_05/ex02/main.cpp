/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 13:43:45 by moseddik         ###   ########.fr       */
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
	return 0;
}