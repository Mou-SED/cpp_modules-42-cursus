/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:15:13 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 23:49:45 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "File could not be opened";
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src), _target(src._target)
{
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other )
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

std::string const	ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

void				ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	AForm::execute(executor);
	std::ofstream file;
	file.open(this->_target + "_shrubbery");
	if (!file.is_open())
		throw FileOpenException();
	file << "|          ccee88oo" << std::endl;
	file << "|       C8O8O8Q8PoOb o8oo" << std::endl;
	file << "|      dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "|     CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "|         6OuU  /p u gcoUodpP" << std::endl;
	file << "|           \\\\\\//  /douUP" << std::endl;
	file << "|            \\\\\\//\\//" << std::endl;
	file << "|             |||/\\/" << std::endl;
	file << "|             |||\\/" << std::endl;
	file << "|             |||||" << std::endl;
	file << "|      .....//||||\\...." << std::endl;
	file.close();
	return ;
}