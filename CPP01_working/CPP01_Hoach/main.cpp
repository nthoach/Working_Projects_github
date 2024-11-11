/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 19:53:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstring>
#include <iostream>

int	main(int agc, char **agv)
{
	std::string	fname;
	std::string	s1;
	std::string s2;

	if (agc != 4)
		return std::cerr << "Usage: " agv[0] << "  <filename> <str1> <str2>" << std::endl, 1;
	
	fname = agv[1];
	s1 = agv[2];
	s2 = agv[3];
	
	//open input file
	std::ifstream iFile(fname.c_str());
	if (iFile.is_open()== 0)
		return std::cerr << "Error: Unable to open " << fname << std::endl, 1;
	
	//open output file
	std::ofstream oFile((fname + ".replace").c_str());
	if (oFile.is_open()== 0)
		return std::cerr << "Error: Unable to create " << fname  << ".replace"<< std::endl, 1;

	//loop to replace s2 by s1
	std::string line;
	std::string buffer = "";
	while (std::getline(iFile, line) != 0)
	{
		size_t start = 0;
		while (start < line.size())
		{
			if (line[start] == s1[0])
			{
				//oFile << line.substr(0, start);
				buffer += line.substr(start);
				if (buffer.size() < s1.size())
				{
					
				}
					break //or return ?? ;
				if (buffer.size() >= s1.size() && buffer.substr(0, s1.size()) == s1)
				{
					oFile << s2;
					start += s1.size();
					buffer = line.substr(start);
				}

				else
				{
					oFile << buffer;
					buffer = "";
				}
			}
			start++;			
		}
		if (start == line.size())
		{
			oFile << line;
			buffer = "";
		}

	}	
	
	return (0);
}
