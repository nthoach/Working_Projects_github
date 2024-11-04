/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:53:40 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/29 19:22:26 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;
	std::string type;
	int nbr;

	if (ac != 2)
	{
		std::cout << "Please give me LEVEL (DEBUG, INFO, WARNING"
		"OR ERROR)" << std::endl;
		return (1);
	}
	nbr = 0;
	type = av[1];
	for (size_t i = 0; i < 4; i++)
	{
		if (type == harl.getStr(i))
			break ;
		nbr++;
	}
	switch (nbr)
	{
	case 0:
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break ;
	case 1:
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break ;
	case 2:
		harl.complain("WARNING");
		harl.complain("ERROR");
		break ;
	case 3:
		harl.complain("ERROR");
		break ;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}
}