/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:35:17 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 16:03:29 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class A_Animal
{
	protected:
		std::string _type;

	public:
		A_Animal( void );
		A_Animal( A_Animal const & src );
		virtual ~A_Animal( void );

		A_Animal & operator=( A_Animal const & other );

		virtual void	makeSound( void ) = 0;
		virtual void	makeSound( void ) const = 0;
		std::string getType( void ) const;
};

#endif