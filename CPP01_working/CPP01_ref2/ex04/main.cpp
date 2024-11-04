/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:37:03 by imontero          #+#    #+#             */
/*   Updated: 2023/12/11 22:37:02 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	findReplaceWrite(std::string infile, const std::string txt, const std::string s1, const std::string s2)
{
	std::ofstream	outfile(infile + ".replace");
	size_t			pos;

	if (!outfile.is_open())
		return (std::cerr << "Unexpected outfile" << std::endl, 1);
	/* if (!s1.length())
		return (0);  */
	for (size_t i = 0; i < txt.length(); i++)
	{
		pos = txt.find(s1, i);
		if (i == pos)
		{
			outfile << s2;
			i += s1.length() - 1;	
		}
		else
			outfile << txt[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	file;
	std::string		txt;
	char			c;
	
	if (argv[1])
		file.open(argv[1]);
	
	if (argc != 4 || !file.is_open())
		return (std::cerr << "USAGE\nThis program needs 3 arguments:\n1st: \
		Existing input file with read permission\n2nd: \
		Ocurrence to be replaced\n3rd: \
		Ocurrence with which to replace" << std::endl, 1);
	
	while (file.get(c))
		txt += c;
	file.close();
			
	return (findReplaceWrite(argv[1], txt, argv[2], argv[3]));
}
