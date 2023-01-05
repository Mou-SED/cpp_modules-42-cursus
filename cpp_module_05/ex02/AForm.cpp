/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:17:06 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/05 14:18:55 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

AForm::AForm( void ) : _name( "Default" ), _grade_to_sign( 150 ), _grade_to_execute( 150 )
{
	return ;
}

AForm::AForm( std::string name, int grade_to_sign, int grade_to_execute )
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
		std::cerr << RED << "AForm Exception: " << e.what() << RESET << std::endl;
		std::cout << RED << "Your AForm: " << this->_name << " has not created you must give him a Grade between 1 and 150" << RESET << std::endl;
		AForm::~AForm();
		e.~exception();
		exit(EXIT_FAILURE);
	}
	return ;
}

AForm::AForm( AForm const & src )
	: _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	return ;
}

AForm & AForm::operator=( AForm const & other )
{
	if (this != &other)
	{
		this->~AForm();
		new (this) AForm(other);
	}
	return (*this);
}

std::ostream & operator<<( std::ostream & o, AForm const & other )
{
	o << "AForm: {Name: " << other.getName() << "} {is_signed: "
		<< (other.getIsSigned() ? "True" : "False")
		<< "} {GradeToSign: " << other.getGradeToSign()
		<< "} {GradeToExecute: " << other.getGradeToExecute()
		<< "}";
	return o;
}

AForm::~AForm( void )
{
	return ;
}

std::string const	AForm::getName( void ) const
{
	return this->_name;
}

bool				AForm::getIsSigned( void ) const
{
	return this->_is_signed;
}

int					AForm::getGradeToSign( void ) const
{
	return this->_grade_to_sign;
}

int 				AForm::getGradeToExecute( void ) const
{
	return this->_grade_to_execute;
}

void	AForm::beSigned( Bureaucrat const & bureaucrat )
{
	try
	{
		if (bureaucrat.getGrade() > this->_grade_to_sign)
			throw GradeTooLowException();
		this->_is_signed = true;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << RED << "AForm Exception: " << e.what() << RESET
			<< " Your Grade is lower than the required grade {" << this->_grade_to_sign << "}, you must raise your Grade to sign the Aform." << std::endl;
	}
	return ;
}