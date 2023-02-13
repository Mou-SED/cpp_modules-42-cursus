/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:10 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/13 17:58:48 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	vec;

	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const & src );
		~Span( void );

		Span const & operator=( Span const & other );

		void	addNumber( int num );
		template< typename I >
		void	addNumbers( I begin, I end );
		int		shortestSpan( void );
		int		longestSpan( void );
		template< typename I >
		void	show( I begin, I end );
		std::vector<int>	getVec( void ) const;
};

#include "Span.tpp"

#endif