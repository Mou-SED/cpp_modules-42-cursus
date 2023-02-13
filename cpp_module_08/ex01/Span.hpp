/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:37:10 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/12 23:07:49 by moseddik         ###   ########.fr       */
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
		void	addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	show( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		std::vector<int>	getVec( void ) const;
};

#endif