/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:27:48 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/30 13:29:30 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];

	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const & src );
		~MateriaSource( void );

		MateriaSource	&operator=( MateriaSource const & other );

		void			learnMateria( AMateria *materia );
		AMateria		*createMateria( std::string const & type );
};

#endif