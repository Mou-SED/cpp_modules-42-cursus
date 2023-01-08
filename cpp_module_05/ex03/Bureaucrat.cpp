/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:16:56 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/08 15:56:04 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name( "Default" ), _grade( 150 )
{
	return ;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name )
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name( src._name ), _grade( src._grade )
{
	return ;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & other )
{
	if (this != &other)
	{
		this->~Bureaucrat();
		new (this) Bureaucrat(other);
	}
	return (*this);
}

std::string const Bureaucrat::getName( void ) const
{
	return this->_name;
}

int		Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void )
{
	short	newGrade = this->getGrade();

	--newGrade;
	if (newGrade < 1)
		throw GradeTooHighException();
	this->_grade = newGrade;
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	short	newGrade = this->getGrade();

	++newGrade;

	if (newGrade > 150)
		throw GradeTooLowException();
	this->_grade = newGrade;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & other )
{
	o << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (o);
}

void	Bureaucrat::signForm( AForm & form )
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << form.getName()
			<< RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName()
			<< " because " << RED << e.what() << RESET << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm( AForm const & form )
{
	if (form.getIsSigned() == false)
	{
		std::cout << RED << this->_name << " couldn't execute " << form.getName()
			<< " because " << form.getName() << " is not signed" << RESET << std::endl;
		return ;
	}
	if (form.getGradeToExecute() < this->getGrade())
	{
		std::cout << RED << this->_name << " couldn't execute " << form.getName()
			<< " because " << form.getGradeToExecute() << " < " << this->getGrade()
				<< " Thus, it does not have the required Grade of AForm" << RESET << std::endl;
		return ;
	}
	form.execute(*this);
	std::cout << GREEN << this->_name << " executed " << form.getName() << RESET << std::endl;
	return ;
}