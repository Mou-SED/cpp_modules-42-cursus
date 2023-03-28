/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:34:02 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/28 13:37:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{
	return ;
}

PmergeMe::PmergeMe( PmergeMe const & src )
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe( void )
{
	return ;
}

PmergeMe & PmergeMe::operator=( PmergeMe const & other )
{
	if (this != &other)
	{
		//TODO: do stuff
	}
	return *this;
}
