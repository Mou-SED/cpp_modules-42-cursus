/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:59:05 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/05 20:14:08 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	_target;

	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & other );
		~ShrubberyCreationForm( void );

		std::string const	getTarget( void ) const;

		void				execute( Bureaucrat const & executor ) const;

		class FileOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
