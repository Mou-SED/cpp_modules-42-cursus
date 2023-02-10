/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:30 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/10 15:53:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char ** av )
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./main <string>" << std::endl;
		return 1;
	}
	std::string input = av[1];
	if (input.length() == 0)
	{
		std::cerr << "String is empty" << std::endl;
		return 1;
	}

	std::string s(av[1]);
	if (!check_input(s))
	{
		std::cerr << "Unkown Type !!!" << std::endl;
	}
	else
	{
		parsing(input);
		ScalarConverter::convert( input );
	}
	return 0;
}