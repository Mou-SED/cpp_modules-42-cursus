/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:51:20 by moseddik          #+#    #+#             */
/*   Updated: 2022/12/04 22:21:25 by moseddik         ###   ########.fr       */
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
	std::string rep_line;
	std::string new_file = filename + ".replace";

	fin.open(filename, std::ios::in);
	if (!fin.is_open())
	{
		std::cout << RED << "Error :( Can't open file" << std::endl;
		return (1);
	}
	fout.open(new_file, std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		std::cout << RED << "Error :( Can't create file" << std::endl;
		return (1);
	}
	while(getline(fin, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			rep_line = line.substr(0, pos);
			rep_line += s2;
			rep_line += line.substr(pos + s1.length());
			line = rep_line;
			pos = line.find(s1);
		}
		std::cout << line << std::endl;
		fout << line << std::endl;
	}
	fin.close();
	fout.close();
	return (0);
}