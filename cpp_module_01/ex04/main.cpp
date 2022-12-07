/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:51:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/07 22:26:10 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << RED << "Error :( Invalid number of arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ofstream fout;
	std::ifstream fin;
	std::string line;
	std::string rep_line;
	std::string new_file = filename + ".replace";

	if (s1 == "")
	{
		std::cout << RED << "Error :( s1 is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	fin.open(filename, std::ios::in);
	if (!fin.is_open())
	{
		std::cout << RED << "Error :( Can't open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	fout.open(new_file, std::ios::out | std::ios::trunc);
	if (!fout.is_open())
	{
		std::cout << RED << "Error :( Can't create file" << std::endl;
		(fin.close(), exit(EXIT_FAILURE));
	}
	while(std::getline(fin, line))
	{
		size_t pos = line.find(s1);
		while (s1 != s2 && pos != std::string::npos)
		{
			rep_line = line.substr(0, pos);
			rep_line += s2;
			rep_line += line.substr(pos + s1.size());
			line = rep_line;
			pos = line.find(s1 , pos + s2.size());
		}
		if (fin.peek() != EOF)
			fout << line << std::endl;
		else
			fout << line;
	}
	std::cout << GREEN << "Done :) check " << RESET << YELLOW << new_file << RESET << std::endl;
	return (fin.close(), fout.close(), EXIT_SUCCESS);
}