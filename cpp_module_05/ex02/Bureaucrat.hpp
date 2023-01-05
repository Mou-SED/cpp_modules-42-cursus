/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:42:25 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/05 14:21:58 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;
# include "AForm.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Bureaucrat
{
	private:
		std::string const   _name;
		int                 _grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat( void );

		Bureaucrat &operator=( Bureaucrat const & other );

		std::string const   getName( void ) const;
		int                 getGrade( void ) const;
		void                incrementGrade( void );
		void                decrementGrade( void );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void	signForm( AForm const & form );
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & other );

#endif