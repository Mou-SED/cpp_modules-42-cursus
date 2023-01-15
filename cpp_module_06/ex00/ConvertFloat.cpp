/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFloat.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:39:12 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 01:55:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::convFloat( std::string const & input )
{
	std::stringstream ss(input);
	float myFloat;
	ss >> myFloat;

	if(!ss.fail())
	{
		int checkPrint = static_cast<int>(myFloat);
		if (checkPrint >= 0 && checkPrint <= 31)
			std::cout << "char: Non displayable" << std::endl;
		else if (checkPrint < 0 || checkPrint > 127)
			std::cout << "char: Non Ascii" << std::endl;
		else
			std::cout << "char: " << "'" << static_cast<char>(checkPrint) << "'" << std::endl;
		std::cout << "int: " << checkPrint << std::endl;
		if ((checkPrint - myFloat) == 0)
			std::cout << "float: " << myFloat << ".0f" << std::endl;
		else
			std::cout << "float: " << myFloat << "f" << std::endl;
		if ((checkPrint - myFloat) == 0)
			std::cout << "double: " << static_cast<double>(myFloat) << ".0" << std::endl;
		else
			std::cout << "double: " << static_cast<double>(myFloat) << std::endl;
	}
	else
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		if (input == "+inf")
		{
			std::cout << "float: " << "inff" << std::endl;
			std::cout << "double: " << "inf" << std::endl;
		}
		else if (input == "-inf")
		{
			std::cout << "float: " << "-inff" << std::endl;
			std::cout << "double: " << "-inf" << std::endl;
		}
		else
		{
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
		}
	}

	return ;
}
