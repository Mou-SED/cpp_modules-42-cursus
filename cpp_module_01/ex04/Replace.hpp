/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 04:37:47 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/04 04:41:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Replace
{
	public:
		Replace();
		~Replace();
	private:
		std::string _name;
};

#endif