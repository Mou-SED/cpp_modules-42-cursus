/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:36:32 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/04 22:03:36 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_grade_to_sign;
		int const			_grade_to_execute;

	public:
		Form( void );
		Form( std::string name, int grade_to_sign, int grade_to_execute );
		Form( Form const & src );
		Form & operator=( Form const & other );
		~Form( void );

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

std::ostream & operator<<( std::ostream & o, Form const & other );

#endif