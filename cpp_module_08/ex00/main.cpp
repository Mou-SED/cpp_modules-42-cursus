/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:57:58 by moseddik          #+#    #+#             */
/*   Updated: 2023/02/12 11:32:10 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
    srand(time(NULL));
    std::vector<int> vec;

    int size = rand() % 100;
    int find = rand() % 100;

    std::cout << "Vector size: " << size << std::endl;
    std::cout << CYAN << "Number to find: " << find << RESET << std::endl;

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % 100);
    }

    std::cout << "Vector: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;

	try
	{
		find = easyfind( vec, find );
		std::cout << GREEN << "Number : " << find << " founded" << RESET << std::endl;
	}
	catch(int const & num)
	{
		std::cerr << RED << "Number Not Found!" << RESET << std::endl;
		return -1;
	}

    return 0;
}