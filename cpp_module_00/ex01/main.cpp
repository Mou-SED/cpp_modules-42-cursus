/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:10:28 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/28 10:26:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
    std::string cmd;

    std::cout << GREEN << "Welcome to my PhoneBook you can write your cmd " << RESET << CYAN << "(ADD || SEARCH || EXIT)" << RESET << GREEN << " here :) " << RESET;
    while(getline(std::cin, cmd))
    {
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
        {
            std::cout << RED << "Please add a contact here: " << RESET << std::endl;
            phonebook.add_contact();
        }
        else if (cmd == "SEARCH")
            phonebook.search_contact();
        else
        {
            std::cout << RED << "Invalid command :( try (ADD or SEARCH or EXIT)" << RESET << std::endl;
        }
        std::cout << GREEN << "Welcome to my PhoneBook you can write your cmd " << RESET << CYAN << " (ADD || SEARCH || EXIT) " << RESET << GREEN << " here :) " << RESET;

    };
	return (0);
}
