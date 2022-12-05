/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:51:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/05 09:07:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
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
	if (s1 == "")
	{
		std::cout << RED << "Error :( s1 is empty" << std::endl;
		(fin.close(), fout.close(), exit(EXIT_FAILURE));
	}
	while(getline(fin, line))
	{
		size_t pos = line.find(s1);
		while (s1 != s2 && pos != std::string::npos)
		{
			rep_line = line.substr(0, pos);
			rep_line += s2;
			rep_line += line.substr(pos + s1.length());
			line = rep_line;
			std::cout << line << std::endl;
			pos = line.find(s1);
		}
		fout << line << std::endl;
	}
	return (fin.close(), fout.close(), EXIT_SUCCESS);
}