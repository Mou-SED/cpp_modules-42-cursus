/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:10:28 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/25 01:49:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
    std::string cmd;

    std::cout << GREEN << "Welcome to my PhoneBook you can write a cmd here :) " << RESET;
    while(getline(std::cin, cmd))
    {
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
        {
            std::cout << RED << "Please add a contact here: " << RESET << std::endl;
            phonebook.add_contact();
        }
        // else if (cmd == "SEARCH")
        //     phonebook.search_contact();
        else
        {
            std::cout << RED << "Invalid command" << RESET << std::endl;
            print_contact(phonebook.get_contact(0));
        }
        std::cout << GREEN << "Welcome to my PhoneBook you can write a cmd here :) " << RESET;
    };
	return (0);
}
