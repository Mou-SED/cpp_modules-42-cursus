/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:33:03 by moseddik          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:09 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RPN_HPP)
#define RPN_HPP

#include <iostream>
#include <stack>
#include "cstdlib"

std::string	removeSpaces( std::string & input );
bool		check_format( std::string input );
int			calculate( std::string & input );

#endif // RPN_HPP
