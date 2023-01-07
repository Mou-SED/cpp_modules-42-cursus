/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:15:13 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/07 12:47:52 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "File could not be opened";
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm parametric constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src), _target(src._target)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other )
{
	std::cout << GREEN << "ShrubberyCreationForm assignation operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
	return ;
}

std::string const	ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

void				ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	try
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
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "ShrubberyCreationForm Exception: "
			<< e.what() << RESET << std::endl;
	}
	return ;
}