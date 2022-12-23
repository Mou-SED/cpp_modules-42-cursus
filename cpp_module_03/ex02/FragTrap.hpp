/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:18:41 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/23 17:43:58 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ScavTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		FragTrap & operator=( FragTrap const & other );

		void	highFivesGuys( void );
};

#endif