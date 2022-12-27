/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:49:32 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/27 16:00:49 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
	private:
		Brain	*_brain;

	public:
		Cat( void );
		Cat( Cat const & src );
		~Cat( void );

		Cat & operator=( Cat const & other );

		void	makeSound( void );
		void	makeSound( void ) const;
};

#endif