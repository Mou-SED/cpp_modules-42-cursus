/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:35:17 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/07 15:08:42 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal( void );
		AAnimal( AAnimal const & src );
		virtual ~AAnimal( void );

		AAnimal & operator=( AAnimal const & other );

		virtual void	makeSound( void ) = 0;
		virtual void	makeSound( void ) const = 0;
		std::string getType( void ) const;
};

#endif