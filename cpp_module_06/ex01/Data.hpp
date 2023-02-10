/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:14:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/10 17:11:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

uintptr_t	serialize( Data* ptr );
Data*		deserialize( uintptr_t raw );

#endif