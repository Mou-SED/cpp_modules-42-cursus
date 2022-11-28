/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:13:12 by moseddik          #+#    #+#             */
/*   Updated: 2022/11/28 10:50:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define GRAY "\033[1;37m"
#define RESET "\033[0m"

class	Contact
{
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

	public:
		std::string	get_first_name(void) const;
		void		set_first_name(std::string first_name);

		std::string	get_last_name(void) const;
		void		set_last_name(std::string last_name);

		std::string	get_nickname(void) const;
		void		set_nickname(std::string nickname);

		std::string	get_phone_number(void) const;
		void		set_phone_number(std::string phone_number);

		std::string	get_darkest_secret(void) const;
		void		set_darkes_secret(std::string darkest_secret);

		Contact( void );
		~Contact( void );
};

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		_index;

	public:
		void	add_contact( void );
		void	search_contact( void );
		Contact	get_contact(int index) const;
		void	set_contact(Contact contact, int index);
		PhoneBook( void );
		~PhoneBook( void );
};

#endif