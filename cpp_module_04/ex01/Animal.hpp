/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:35:17 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 00:09:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal( void );
		Animal( Animal const & src );
		virtual ~Animal( void );

		Animal & operator=( Animal const & other );

		virtual void	makeSound( void );
		virtual void	makeSound( void ) const;
		std::string getType( void ) const;
};

#endif