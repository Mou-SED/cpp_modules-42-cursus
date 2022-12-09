/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:07:25 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/09 03:54:25 by moseddik         ###   ########.fr       */
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
	typedef void (Harl::*Func)(void);
	Func func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func[i])();
			return ;
		}
	}
	std::cout << "INVALID MODE!" << std::endl;
}
