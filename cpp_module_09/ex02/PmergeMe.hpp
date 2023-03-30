/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:33:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/30 13:31:35 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <cstring>

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( int ac, char **av, size_t size );
		PmergeMe( PmergeMe const & src );
		~PmergeMe( void );

		PmergeMe & operator=( PmergeMe const & other );

		void	runVector( void );
		void	runDeque( void );
		void	printBefore( void ) const;
		void	printAfter( void ) const;

		double	getTimeUsedVector( void ) const;
		double	getTimeUsedDqueue( void ) const;

		void	setTimeUsedVector( double time );
		void	setTimeUsedDqueue( double time );

	private:
		int _ac;
		char **_av;
		std::vector<int> _vec;
		std::deque<int> _deq;
		size_t _size;
		double _timeUsedVector;
		double _timeUsedDqueue;
};

void	insertionSort( std::vector<int> & arr, int left, int right );
void	merge( std::vector<int> & arr, int left, int mid, int right );
void	mergeInsertionSort( std::vector<int> & arr, int left, int right );

void	insertionSort( std::deque<int> & arr, int left, int right );
void	merge( std::deque<int> & arr, int left, int mid, int right );
void	mergeInsertionSort( std::deque<int> & arr, int left, int right );

#endif