/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:05:45 by moseddik          #+#    #+#             */
/*   Updated: 2023/01/17 19:34:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

//! My test
// int main( void )
// {
//     Array< std::string > arr1;
//     Array< std::string > arr2(5);

//     std::cout << "arr1 size: " << arr1.size() << std::endl;
//     std::cout << "arr2 size: " << arr2.size() << std::endl;
//     try
// 	{
//         arr2[5] = "Hello";
//     } catch (std::exception& e)
// 	{
//         std::cout << "Exception: " << e.what() << std::endl;
//     }

//     arr2[3] = "Hello";
//     std::cout << "arr2[3]: " << arr2[3] << std::endl;

//     Array< std::string > arr3(arr2);
//     std::cout << "arr3 size: " << arr3.size() << std::endl;

//     arr3[3] = "World";
//     std::cout << "arr2[3]: " << arr2[3] << std::endl;
//     std::cout << "arr3[3]: " << arr3[3] << std::endl;

//     Array< std::string > arr4;
//     arr4 = arr3;
//     std::cout << "arr4 size: " << arr4.size() << std::endl;

//     arr4[3] = "C++";
//     std::cout << "arr3[3]: " << arr3[3] << std::endl;
//     std::cout << "arr4[3]: " << arr4[3] << std::endl;

//     return 0;
// }
