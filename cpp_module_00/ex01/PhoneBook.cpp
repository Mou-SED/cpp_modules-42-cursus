/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:39:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/25 01:51:41 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
	: _index(0)
{
	return ;
};

PhoneBook::~PhoneBook(void)
{
	return ;
};

Contact::Contact(void)
	: _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
	return ;
};

Contact::~Contact(void)
{
	return ;
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

void	PhoneBook::add_contact()
{
	Contact	contact;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name: ";
	std::getline(std::cin, first_name);
	if (std::cin.eof() || first_name == "")
		return ;
	this->contacts[this->_index].set_first_name(first_name);
	std::cout << "Last name: ";
	std::getline(std::cin, last_name);
	contact.set_last_name(last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	contact.set_nickname(nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	contact.set_phone_number(phone_number);
}

void	print_contact(Contact contact)
{
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
}