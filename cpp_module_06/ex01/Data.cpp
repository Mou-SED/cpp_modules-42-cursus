/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:16:21 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 02:25:04 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize( Data* ptr )
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		deserialize(  uintptr_t raw )
{
	return ( reinterpret_cast<Data*>(raw) );
}
