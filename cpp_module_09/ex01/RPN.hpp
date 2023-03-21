/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:33:03 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 20:39:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RPN_HPP)
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <exception>
#include <stdexcept>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

std::string	removeSpaces( std::string & input );
bool		check_format( std::string input );
int			calculate( std::string & input );

#endif // RPN_HPP
