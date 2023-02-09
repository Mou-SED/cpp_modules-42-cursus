/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertDouble.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:40:17 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/09 22:29:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void	Convert::convDouble( std::string const & input )
{
	std::stringstream ss(input);
	double myDouble;
	ss >> myDouble;

	if (ss.fail())
	{
		std::cerr << "Unkown Type !!!" << std::endl;
		return ;
	}
	int checkPrint = static_cast<int>(myDouble);
	if (checkPrint >= 0 && checkPrint <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (checkPrint < 0 || checkPrint > 127)
		std::cout << "char: Non Ascii" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(checkPrint) << "'" << std::endl;
	std::cout << "int: " << checkPrint << std::endl;
	if ((checkPrint - myDouble) == 0)
		std::cout << "float: " << static_cast<float>(myDouble) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(myDouble) << "f" << std::endl;
	if ((checkPrint - myDouble) == 0)
		std::cout << "double: " << myDouble << ".0" << std::endl;
	else
		std::cout << "double: " << myDouble << std::endl;

	return ;
}
