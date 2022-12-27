/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:30:22 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 13:42:58 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain( void );
		Brain( Brain const & src );
		~Brain( void );

		Brain & operator=( Brain const & other );
};

#endif