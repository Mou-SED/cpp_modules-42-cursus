/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:30:42 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/30 18:46:56 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i] != nullptr)
			this->_materias[i] = src._materias[i]->clone();
		else
			this->_materias[i] = nullptr;
	}
	return ;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != nullptr)
        {
            delete _materias[i];
            this->_materias[i] = nullptr;
        }
	}
	return ;
}

MateriaSource	&MateriaSource::operator=( MateriaSource const & other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i] != nullptr)
			{
				delete this->_materias[i];
				this->_materias[i] = nullptr;
			}
			if (other._materias[i] != nullptr)
				this->_materias[i] = other._materias[i]->clone();
		}
	}
	return (*this);
}

void			MateriaSource::learnMateria( AMateria *materia )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == nullptr)
		{
			this->_materias[i] = materia->clone();
			return ;
		}
	}
	return ;
}

AMateria		*MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != nullptr && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (nullptr);
}