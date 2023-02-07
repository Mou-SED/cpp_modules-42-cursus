/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:45:37 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 15:08:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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