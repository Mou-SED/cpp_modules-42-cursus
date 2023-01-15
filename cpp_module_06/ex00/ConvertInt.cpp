/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:38:32 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 01:55:28 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::convInt( std::string const & input )
{
	std::stringstream ss(input);
	int myInt;
	ss >> myInt;

	if (ss.fail() || input.find("."))
	{
		std::cout << "Please fill a valid Int or float or double or char" << std::endl;
		return ;
	}
	if (myInt >= 0 && myInt <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (myInt < 0 || myInt > 127)
		std::cout << "char: Non Ascii" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(myInt) << std::endl;
	std::cout << "int: " << myInt << std::endl;
	std::cout << "float: " << static_cast<float>(myInt) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(myInt) << ".0" << std::endl;

	return ;
}
