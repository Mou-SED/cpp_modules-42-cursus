/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:38:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/04 23:24:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

Form::Form( void ) : _name( "Default" ), _grade_to_sign( 150 ), _grade_to_execute( 150 )
{
	return ;
}

Form::Form( std::string name, int grade_to_sign, int grade_to_execute )
	: _name( name ), _grade_to_sign( grade_to_sign ), _grade_to_execute( grade_to_execute )
{
	try
	{
		if (grade_to_sign < 1 || grade_to_execute < 1)
			throw GradeTooHighException();
		if (grade_to_sign > 150 || grade_to_execute > 150)
			throw GradeTooLowException();
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Form Exception: " << e.what() << RESET << std::endl;
		std::cout << RED << "Your Form: " << this->_name << " has not created you must give him a Grade between 1 and 150" << RESET << std::endl;
		Form::~Form();
		exit(EXIT_FAILURE);
	}
	return ;
}

Form::Form( Form const & src )
	: _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	return ;
}

Form & Form::operator=( Form const & other )
{
	if (this != &other)
	{
		this->~Form();
		new (this) Form(other);
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, Form const & other )
{
	o << "Form: {Name: " << other.getName() << "} {is_signed: "
		<< (other.getIsSigned() ? "True" : "False")
		<< "} {GradeToSign: " << other.getGradeToSign()
		<< "} {GradeToExecute: " << other.getGradeToExecute()
		<< "}";
	return o;
}

Form::~Form( void )
{
	return ;
}

std::string const	Form::getName( void ) const
{
	return this->_name;
}

bool				Form::getIsSigned( void ) const
{
	return this->_is_signed;
}

int					Form::getGradeToSign( void ) const
{
	return this->_grade_to_sign;
}

int 				Form::getGradeToExecute( void ) const
{
	return this->_grade_to_execute;
}

void	Form::beSigned( Bureaucrat const & bureaucrat )
{
	try
	{
		if (bureaucrat.getGrade() > this->_grade_to_sign)
			throw GradeTooLowException();
		this->_is_signed = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << RED << "Form Exception: " << e.what() << RESET
			<< " Your Grade is lower than the required grade {" << this->_grade_to_sign << "}, you must raise your Grade to sign the form." << std::endl;
	}
	return ;
}