/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:02:01 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/17 01:43:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template< typename T >
void	iter( T *arr, std::size_t len, void (*func)( T const & ) )
{
	for ( std::size_t i = 0; i < len; i++)
	{
		func( arr[i] );
	}
	return ;
}

template< typename T >
void	iter( T *arr, std::size_t len, void (*func)( T & ) )
{
	for ( std::size_t i = 0; i < len; i++)
	{
		func( arr[i] );
	}
	return ;
}

#endif