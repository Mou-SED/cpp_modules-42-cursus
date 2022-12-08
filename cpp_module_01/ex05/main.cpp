/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:04:52 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/08 15:00:16 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ( void )
{
	Harl harl;

	harl.comlain("DEBUG");
	harl.comlain("INFO");
	harl.comlain("WARNING");
	harl.comlain("ERROR");
	harl.comlain("INVALID");

	return (0);
}