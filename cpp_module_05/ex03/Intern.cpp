/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:37:32 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 23:36:18 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

Intern::Intern( void )
{
	std::cout << GREEN << "Intern created" << RESET << std::endl;
	return ;
}

Intern::Intern( Intern const & src )
{
	*this = src;
	return ;
}

Intern::~Intern( void )
{
	std::cout << RED << "Intern destroyed" << RESET << std::endl;
	return ;
}

Intern & Intern::operator=( Intern const & other )
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm( std::string formName, std::string target )
{
	AForm *form = nullptr;
	int	formIndex = 404;

	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
			formIndex = i;
	}

	switch (formIndex)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::FormNotFoundException();
			break;
	}
	if (form)
		std::cout << BLUE << "Intern creates " << form->getName() << RESET << std::endl;
	return (form);
}