/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:07 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/13 17:59:24 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template< typename I >
void	Span::addNumbers( I begin, I end )
{
	if (this->vec.size() + (end - begin) > this->_size)
		throw 406;
	this->vec.insert( vec.end(), begin, end );

	return ;
}

template< typename I >
void	Span::show( I begin, I end )
{
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}

	return ;
}