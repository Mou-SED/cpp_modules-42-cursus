/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:17:17 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/05 14:18:02 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_grade_to_sign;
		int const			_grade_to_execute;

	public:
		AForm( void );
		AForm( std::string name, int grade_to_sign, int grade_to_execute );
		AForm( AForm const & src );
		AForm & operator=( AForm const & other );
		~AForm( void );

		std::string const	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute( void ) const;

		void				beSigned( Bureaucrat const & bureaucrat );

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
};

std::ostream & operator<<( std::ostream & o, AForm const & other );

#endif