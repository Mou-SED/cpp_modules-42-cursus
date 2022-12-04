/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 04:55:55 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/02 17:22:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define RED "\033[31m"
#define RESET "\033[0m"

int main( void )
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPtr = &str;
	std::string &stringRef = str;

	std::cout << std::endl;

	std::cout << "Address of str: " << RED << &str << RESET << std::endl;
	std::cout << "Address of stringPtr: " << RED << stringPtr << RESET << std::endl;
	std::cout << "Address of stringRef: " << RED << &stringRef << RESET << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str: " << RED << str << RESET << std::endl;
	std::cout << "Value of stringPtr: " << RED << *stringPtr << RESET << std::endl;
	std::cout << "Value of stringRef: " << RED << stringRef << RESET << std::endl;

	std::cout << std::endl;
	return (EXIT_SUCCESS);
}