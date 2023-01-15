/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertChar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:37:53 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 01:47:21 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::convChar( std::string const & input )
{
	int checkPrint = static_cast<int>(input.front());
	std::stringstream ss(input);
	char myChar;
	ss >> myChar;

	if (checkPrint >= 0 && checkPrint <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (checkPrint < 0 || checkPrint > 127)
		std::cout << "char: Non Ascii" << std::endl;
	else
		std::cout << "char: " << "'" << myChar << "'" << std::endl;
	std::cout << "int: " << checkPrint << std::endl;
	std::cout << "float: " << static_cast<float>(myChar) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(myChar) << ".0" << std::endl;

	return ;
}
