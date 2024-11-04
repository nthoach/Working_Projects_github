/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:38:21 by imontero          #+#    #+#             */
/*   Updated: 2023/12/11 18:43:06 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;

		harl.complain(argv[1]);
	}
	else
		std::cout << "Usage: ./harl [DEBUG, INFO, WARNING, ERROR]" << std::endl;
	return (0);
}