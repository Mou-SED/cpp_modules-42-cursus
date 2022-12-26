/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:26:59 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/26 17:39:19 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal( void );

		WrongAnimal & operator=( WrongAnimal const & other );

		void	makeSound( void );
		void	makeSound( void ) const;
		std::string getType( void ) const;
};

#endif