/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:30 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/09 22:25:22 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool check_input(std::string &str)
{
	bool hasDot = false;
	bool hasFloat = false;
	if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "nan" || str == "nanf")
		return (true);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i != 0 && (str[i] != 'f' && str[i] != '.' && str[i] != '+' && str[i] != '-' && !isdigit(str[i])) )
			return false;
		if (str[i] == '.')
		{
			if (hasDot)
                return false;
            else
                hasDot = true;
		}
		if (str[i] == 'f')
		{
			if (hasFloat)
                return false;
            else
                hasFloat = true;
		}
	}
	if (!hasDot && hasFloat)
		return false;
	return true;
}

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

	Convert conv;
	std::string s(av[1]);
	if (!check_input(s))
	{
		std::cerr << "Unkown Type !!!" << std::endl;
	}
	else
	{
		conv.parsing(input);

		// Print the type of the input
		switch (conv.getLiteralType())
		{
			case (Convert::CHAR):
				conv.convChar( input );
				break;
			case (Convert::INTEGER):
				conv.convInt( input );
				break;
			case (Convert::FLOAT):
				conv.convFloat( input );
				break;
			case (Convert::DOUBLE):
				conv.convDouble( input );
				break;
			default:
			{
				break ;
			}
		}
	}
	return 0;
}