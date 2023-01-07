/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:37:04 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 14:16:19 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm parametric constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
	: AForm(src), _target(src._target)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & other )
{
	std::cout << GREEN << "PresidentialPardonForm assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
	return ;
}

std::string const	PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute(executor);
	std::cout << BLUE << this->_target
		<< " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}