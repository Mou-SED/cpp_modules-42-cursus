/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:33:41 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/28 13:37:09 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>

class PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		~PmergeMe( void );

		PmergeMe & operator=( PmergeMe const & other );

	private:
};

#endif