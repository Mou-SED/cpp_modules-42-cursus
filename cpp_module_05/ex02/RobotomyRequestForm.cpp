/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:48 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 13:35:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm parametric constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
	: AForm(src), _target(src._target)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & other )
{
	std::cout << GREEN << "RobotomyRequestForm assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
	return ;
}

std::string const	RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		AForm::execute(executor);
		std::cout << "Drilling noises..." << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " robotomization failed" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "RobotomyRequestForm Exception: "
			<< e.what() << RESET << std::endl;
		return ;
	}
	return ;
}