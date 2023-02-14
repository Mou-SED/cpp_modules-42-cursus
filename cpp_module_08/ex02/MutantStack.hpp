/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:59:09 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/14 14:38:06 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <deque>

template< typename T , typename C = std::deque<T> >
class MutantStack : public std::stack< T, C >
{
	public:
		MutantStack( void ) {};
		MutantStack( MutantStack const & src ) : std::stack< T, C >(src) {};
		~MutantStack( void ) {};

		MutantStack const & operator=( MutantStack const & other )
		{
			std::stack< T, C >::operator=(other);
			return (*this);
		};

		typedef typename std::stack< T, C >::container_type::iterator iterator;

		iterator	begin( void )
		{
			return (std::stack< T, C >::c.begin());
		};
		iterator	end( void )
		{
			return (std::stack< T, C >::c.end());
		};

};

#endif