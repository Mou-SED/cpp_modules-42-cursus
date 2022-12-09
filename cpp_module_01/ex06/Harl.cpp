/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:07:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/09 03:50:42 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "DEBUG MODE!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO MODE!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING MODE!" << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR MODE!" << std::endl;
}

void Harl::complain( std::string level )
{
	int Level = 404;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			Level = i;
	}

	switch (Level)
	{
		case 0:
		{
			std::cout << RED << "[ DEBUG ]" << RESET << std::endl;
			this->debug();
			std::cout << std::endl;
		}
		case 1:
		{
			std::cout << RED << "[ INFO ]" << RESET << std::endl;
			this->info();
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << RED << "[ WARNING ]" << RESET << std::endl;
			this->warning();
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << RED << "[ ERROR ]" << RESET << std::endl;
			this->error();
			std::cout << std::endl;
			break ;
		}
		default:
			std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
	}
}
