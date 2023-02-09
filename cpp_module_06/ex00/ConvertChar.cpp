/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:37:53 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/09 22:54:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::convChar( std::string const & input )
{
	char myChar;
	myChar = input[0];

	int checkPrint = myChar - 48;
	if (checkPrint >= 0 && checkPrint <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (checkPrint < 0 || checkPrint > 127)
		std::cout << "char: Non Ascii" << std::endl;
	else
		std::cout << "char: " << "'" << checkPrint << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(checkPrint) << std::endl;
	std::cout << "float: " << static_cast<float>(checkPrint) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(checkPrint) << ".0" << std::endl;

	return ;
}
