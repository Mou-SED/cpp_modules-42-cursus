/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:14:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 02:43:43 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	std::string s1 = "Default";
	int n = 0;
	std::string s2 = "Default";
};

uintptr_t	serialize( Data* ptr );
Data*		deserialize( uintptr_t raw );

#endif