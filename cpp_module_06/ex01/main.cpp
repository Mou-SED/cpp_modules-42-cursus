/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:16:56 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/15 02:52:17 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main( void )
{
	Data*	data = new(std::nothrow) Data;
	if (data == nullptr)
	{
		std::cout << "Error: Failed to allocate memory for Data object" << std::endl;
		return 1;
	}
	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "Before serialization:" << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	uintptr_t	serialized = serialize(data);
	Data*		deserialized = deserialize(serialized);

	std::cout << "After serialization:" << std::endl;
	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;

	delete data;
	return (0);
}