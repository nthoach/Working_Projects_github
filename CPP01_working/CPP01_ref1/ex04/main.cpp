/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:44:21 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/29 11:43:46 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

enum	Error
{
	ARG,
	INPUT,
	OUTPUT
};

int	printError(int err)
{
	if (err == ARG)
		std::cerr << "Wrong number of arguments, "
						"use ./replace file s1 s2"
					<< std::endl;
	else if (err == INPUT)
		std::cerr << "Input file error!" << std::endl;
	else if (err == OUTPUT)
		std::cerr << "Output file error!" << std::endl;
	return (1);
}

void	replaceString(
	std::ifstream &inputFile,
	std::ofstream &outputFile,
	const std::string &oldStr,
	const std::string &newStr)
{
	size_t	pos;

	std::string line;
	while (std::getline(inputFile, line))
	{
		pos = line.find(oldStr);
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + newStr + line.substr(pos
					+ oldStr.length());
			pos = line.find(oldStr, pos + newStr.length());
		}
		outputFile << line << std::endl;
	}
}

int	main(int ac, char **av)
{
	std::string s1;
	std::string s2;
	std::string inputPath;
	std::string outputPath;
	std::ifstream inputFile;
	std::ofstream outputFile;

	if (ac != 4)
		return (printError(ARG));

	s1 = av[2];
	s2 = av[3];
	inputPath = av[1];
	inputFile.open(inputPath.c_str());
	if (!inputFile.good())
		return (printError(INPUT));
	outputPath = inputPath + ".replace";
	outputFile.open(outputPath.c_str());
	if (!outputFile.good())
	{
		inputFile.close();
		return (printError(OUTPUT));
	}
	replaceString(inputFile, outputFile, s1, s2);
	inputFile.close();
	outputFile.close();
	return (0);
}