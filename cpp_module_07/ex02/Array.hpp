/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:06:19 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/17 19:11:34 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ARRAY_HPP
# define	ARRAY_HPP

# include <stdexcept>
# include <iostream>
# include <string>

template< typename T >
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array( void ) : _array(nullptr), _size(0) {}

		Array( unsigned int n ) : _size( n )
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = T();
		}

		Array( Array const & src )
			: _size( src._size )
		{
			try
			{
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			catch(const std::bad_alloc& e)
			{
				_array = nullptr;
				_size = 0;
				std::cerr << e.what() << std::endl;
			}
		}

		~Array( void ) { delete[] _array; }

		Array & operator=( Array const & other )
		{
			if (this != &other)
			{
				try
				{
					_size = other._size;
					delete [] _array;
					_array = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_array[i] = other._array[i];
				}
				catch(const std::bad_alloc& e)
				{
					_array = nullptr;
					_size = 0;
					std::cerr << e.what() << std::endl;
				}
			}
			return *this;
		}

		T & operator[]( unsigned int index )
		{
			if (index >= _size)
				throw std::runtime_error("index is out of bounds");
			return _array[index];
		}

		size_t	size( void ) const
		{
			return (this->_size);
		}
};

#endif