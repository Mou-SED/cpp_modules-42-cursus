/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:39:59 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/13 17:59:04 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
	: _size( 0 )
{
	return ;
}

Span::Span( unsigned int N )
	: _size( N )
{
	return ;
}

Span::Span( Span const & src )
{
	*this = src;
	return ;
}

Span::~Span( void )
{
	return ;
}

Span const & Span::operator=( Span const & other )
{
	if (this != &other)
	{
		this->_size = other._size;
		this->vec = other.vec;
	}

	return (*this);
}

void	Span::addNumber( int num )
{
	if (this->vec.size() >= this->_size)
		throw 404;
	this->vec.push_back(num);
	return ;
}

int		Span::shortestSpan( void )
{
	if (this->vec.size() == 1 || this->vec.size() == 0)
		throw 405;
	std::sort( this->vec.begin(), this->vec.end() );
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < vec.size(); i++)
	{
        int span = vec[i] - vec[i-1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
	return 0;
}

int		Span::longestSpan( void )
{
	if (this->vec.size() == 1 || this->vec.size() == 0)
		throw 405;
	std::sort( this->vec.begin(), this->vec.end() );
	int maxSpan = vec[vec.size() - 1] - vec[0];
    return maxSpan;
	return 0;
}

std::vector<int>	Span::getVec( void ) const
{
	return (this->vec);
}