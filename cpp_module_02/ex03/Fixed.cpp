/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:02:02 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/17 12:54:34 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( int const value )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = value << this->_fractional_bits;
	return ;
}

Fixed::Fixed( float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(value * (float)(1 << this->_fractional_bits));
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed & Fixed::operator=( Fixed const & other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed_point_value = other._fixed_point_value;

	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed_point_value >> this->_fractional_bits);
}

std::ostream & operator<<( std::ostream & o, Fixed const & other )
{
	o << other.toFloat();
	return (o);
}

bool Fixed::operator>( Fixed const & other ) const
{
	return (this->_fixed_point_value > other._fixed_point_value);
}

bool Fixed::operator<( Fixed const & other ) const
{
	return !(*this >= other);
}

bool Fixed::operator>=( Fixed const & other ) const
{
	return (this->_fixed_point_value >= other._fixed_point_value);
}

bool Fixed::operator<=( Fixed const & other ) const
{
	return !(*this > other);
}

bool Fixed::operator==( Fixed const & other ) const
{
	return (this->_fixed_point_value == other._fixed_point_value);
}

bool Fixed::operator!=( Fixed const & other ) const
{
	return !(*this == other);
}

Fixed Fixed::operator+( Fixed const & other ) const
{
	Fixed result;

	result._fixed_point_value = this->_fixed_point_value + other._fixed_point_value;
	return (result);
}

Fixed Fixed::operator-( Fixed const & other ) const
{
	Fixed result;

	result._fixed_point_value = this->_fixed_point_value - other._fixed_point_value;
	return (result);
}

Fixed Fixed::operator*( Fixed const & other ) const
{
	Fixed result;

	result._fixed_point_value = (this->_fixed_point_value * other._fixed_point_value) >> this->_fractional_bits;
	return (result);
}

Fixed Fixed::operator/( Fixed const & other ) const
{
	Fixed result;

	result._fixed_point_value = (this->_fixed_point_value << this->_fractional_bits) / other._fixed_point_value;
	return (result);
}

Fixed & Fixed::operator++( void )
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed result(*this);

	this->_fixed_point_value++;
	return (result);
}

Fixed & Fixed::operator--( void )
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed result(*this);

	this->_fixed_point_value--;
	return (result);
}

Fixed & Fixed::min( Fixed & a, Fixed & b )
{
	return (a < b ? a : b);
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b )
{
	return (a < b ? a : b);
}

Fixed & Fixed::max( Fixed & a, Fixed & b )
{
	return (a > b ? a : b);
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b )
{
	return (a > b ? a : b);
}
