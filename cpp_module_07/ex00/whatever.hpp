/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:46:01 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/16 13:41:36 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cstring>

template< typename T >
void		swap( T & a, T & b )
{
	T tmp = a;
	a = b;
	b = tmp;

	return ;
}

template< typename T >
T const &	min( T const & a, T const & b )
{
	return ( a < b ? a : b );
}

char *		min( char* a, char* b )
{
	if (std::strcmp( a, b ) < 0)
		return a;
	return ( b );
}

const char*	min( const char* a, const char* b )
{
	if (std::strcmp( a, b ) < 0)
		return a;
	return ( b );
}

template< typename T >
T const &	max( T const & a, T const & b )
{
	return ( a > b ? a : b );
}

char *		max( char* a, char* b )
{
	if (std::strcmp( a, b ) > 0)
		return a;
	return ( b );
}

const char*	max( const char* a, const char* b )
{
	if (std::strcmp( a, b ) > 0)
		return a;
	return ( b );
}

#endif