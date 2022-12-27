/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:45:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 16:00:59 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal
{
	private:
		Brain	*_brain;

	public:
		Dog( void );
		Dog( Dog const & src );
		~Dog( void );

		Dog & operator=( Dog const & other );

		void	makeSound( void );
		void	makeSound( void ) const;
};

#endif