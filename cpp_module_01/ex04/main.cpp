/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:51:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/04 05:11:01 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << RED << "Error :( Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ofstream fout;
	std::ifstream fin;
	std::string line;
	std::string new_file = filename + ".replace";

	fin.open(filename, std::ios::in);
	if (!fin.is_open())
	{
		std::cout << RED << "Error :( Can't open file" << std::endl;
		return (1);
	}
	fout.open(new_file, std::ios::out | std::ios::trunc);
	if (!fout.is_open())
	{
		std::cout << RED << "Error :( Can't create file" << std::endl;
		return (1);
	}
	while (std::getline(fin, line))
	{
		while (line.find(s1) != std::string::npos)
			line.replace(line.find(s1), s1.length(), s2);
		fout << line << std::endl;
	}
	std::cout << "filename: " << filename << std::endl;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	return (0);
}