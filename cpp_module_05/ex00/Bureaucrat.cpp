/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:16:56 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/04 23:47:46 by moseddik         ###   ########.fr       */
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
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
		std::cout << RED << "Your Bureaucrat: " << this->_name
			<< " has not created you must give him a Grade between 1 and 150" << RESET << std::endl;
		Bureaucrat::~Bureaucrat();
		e.~exception();
		exit(EXIT_FAILURE);
	}
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
	try
	{
		if (newGrade < 1)
			throw GradeTooHighException();
		this->_grade = newGrade;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	short	newGrade = this->getGrade();

	++newGrade;
	try
	{
		if (newGrade > 150)
			throw GradeTooLowException();
		this->_grade = newGrade;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
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