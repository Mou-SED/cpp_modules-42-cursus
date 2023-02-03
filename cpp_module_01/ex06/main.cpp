/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:12:40 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/03 18:44:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./HarlFilter [DEBUG, INFO, WARNING, ERROR]" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	Harl harl;

	harl.complain(av[1]);
	return (0);
}