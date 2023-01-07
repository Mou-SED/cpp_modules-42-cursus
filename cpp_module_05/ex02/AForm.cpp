/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:17:06 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 14:33:24 by moseddik         ###   ########.fr       */
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

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

AForm::AForm( void ) : _name( "Default" ), _grade_to_sign( 150 ), _grade_to_execute( 150 )
{
	return ;
}

AForm::AForm( std::string name, int grade_to_sign, int grade_to_execute )
	: _name( name ), _grade_to_sign( grade_to_sign ), _grade_to_execute( grade_to_execute )
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
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
		this->_is_signed = other._is_signed;
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
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
	return ;
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if (this->_is_signed == false)
	{
		throw FormNotSignedException();
	}

	if (executor.getGrade() > this->_grade_to_execute)
	{
		throw GradeTooLowException();
	}
	return ;
}