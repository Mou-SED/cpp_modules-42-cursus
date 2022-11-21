/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:48 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/21 14:47:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main (int ac, char **av)
{
	int			i;
	int			j;
	std::string	str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			str = av[i];
			j = 0;
			while (str[j])
			{
				std::cout << (char)toupper(str[j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
