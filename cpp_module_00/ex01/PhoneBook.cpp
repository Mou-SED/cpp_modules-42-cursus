/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:39:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/28 10:52:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
	: _index(0)
{
};

PhoneBook::~PhoneBook(void)
{
};

Contact::Contact(void)
	: _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
};

Contact::~Contact(void)
{
};

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

void		Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

void		Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

void		Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

void		Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

void		Contact::set_darkes_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

Contact		PhoneBook::get_contact(int index) const
{
	return (this->contacts[index]);
}

void		PhoneBook::set_contact(Contact contact, int index)
{
	this->contacts[index] = contact;
}

int 	is_space(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	read_input(std::string &input, std::string message)
{
	while (true)
	{
		std::cout << MAGENTA << message << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (!(input.empty()) && !is_space(input))
			break ;
	}
}

void	PhoneBook::add_contact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	read_input(first_name, "First name: ");
	this->contacts[this->_index].set_first_name(first_name);

	read_input(last_name, "Last name: ");
	this->contacts[this->_index].set_last_name(last_name);

	read_input(nickname, "Nickname: ");
	this->contacts[this->_index].set_nickname(nickname);

	read_input(phone_number, "Phone number: ");
	this->contacts[this->_index].set_phone_number(phone_number);

	read_input(darkest_secret, "Darkest secret: ");
	this->contacts[this->_index].set_darkes_secret(darkest_secret);

	this->_index = (this->_index + 1) % 8;
}

void	PhoneBook::search_contact()
{
	int	i;
	static int count;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	index;
	size_t		start;
	size_t		end;

	i = 0;
	std::cout << std::endl;
	std::cout << "*----------------------------------------------*" << std::endl;
	std::cout << "*  index  | first name | last name | nickname  *" << std::endl;
	std::cout << "*----------------------------------------------*" << std::endl;
	while (i < 8)
	{
		if (this->contacts[i].get_first_name() != "")
		{
			std::cout << std::setw(10) << i + 1 << "|";
			first_name = this->contacts[i].get_first_name();
			start = first_name.find_first_not_of(" \t");
			end = first_name.find_last_not_of(" \t");
			first_name = first_name.substr(start, end - start + 1);
			if (first_name.size() > 10)
				first_name = first_name.substr(0, 9) + ".";
			std::cout << std::setw(12) << first_name << "|";

			last_name = this->contacts[i].get_last_name();
			start = last_name.find_first_not_of(" \t");
			end = last_name.find_last_not_of(" \t");
			last_name = last_name.substr(start, end - start + 1);
			if (last_name.size() > 10)
				last_name = last_name.substr(0, 9) + ".";
			std::cout << std::setw(11) << last_name << "|";

			nickname = this->contacts[i].get_nickname();
			start = nickname.find_first_not_of(" \t");
			end = nickname.find_last_not_of(" \t");
			nickname = nickname.substr(start, end - start + 1);
			if (nickname.size() > 10)
				nickname = nickname.substr(0, 9) + ".";
			std::cout << std::setw(11) << nickname << std::endl;
			std::cout << "*----------------------------------------------*" << std::endl;
			count++;
		}
		i++;
	}
	std::cout << std::endl;
	if (count != 0)
	{
		std::cout << CYAN << "Enter the index of the contact you want to see from the table above: " << RESET;
		getline(std::cin, index);
		if (index.size() == 1 && index[0] > '0' && index[0] <= '8')
		{
			std::cout << std::endl;
			std::cout << RED << "|" << "\t" << "First name: " << RESET << this->contacts[index[0] - '1'].get_first_name() << std::endl;
			std::cout << RED << "|" << "\t" << "Last name: " << RESET << this->contacts[index[0] - '1'].get_last_name() << std::endl;
			std::cout << RED << "|" << "\t" << "Nickname: " << RESET << this->contacts[index[0] - '1'].get_nickname() << std::endl;
			std::cout << RED << "|" << "\t" << "Phone number: " << RESET << this->contacts[index[0] - '1'].get_phone_number() << std::endl;
			std::cout << RED << "|" << "\t" << "Darkest secret: " << RESET << this->contacts[index[0] - '1'].get_darkest_secret() << std::endl;
			std::cout << std::endl;
		}
	}
	else
		std::cout << YELLOW << "There is no contact to show use cmd ADD to add a contact" << std::endl;
}
