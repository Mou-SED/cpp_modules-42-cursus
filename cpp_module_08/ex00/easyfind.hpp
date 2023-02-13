/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:59:22 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/13 16:38:22 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

template< typename T >
int	easyfind( T & container, int const & find )
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it != container.end())
        return *it;
	throw 404;
	return -1;
}

#endif
