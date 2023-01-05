/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:30:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/05 20:38:03 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Bureaucrat bureaucrat("Bureaucrat", 130);

	ShrubberyCreationForm form("ShrubberyCreationForm");
	form.beSigned(bureaucrat);
	std::cout << form << std::endl;
	bureaucrat.signForm(form);
	form.execute(bureaucrat);
	return 0;
}