/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:01:03 by imontero          #+#    #+#             */
/*   Updated: 2023/12/11 18:56:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}
/*
	uses switch case to call the appropriate function
*/
void	Harl::complain(std::string level)
{
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*ptrComplain[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (level == lvl[i])
		{
			(this->*ptrComplain[i])();
			return ;
		}
	}
	std::cout << "Unexpected input" << std::endl;
}

void	Harl::_debug(void)
{
	std::cout << "Debug messages contain contextual information. They are mostly used for problem diagnosis" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "Info messages contain extensive information. They are helpful for tracing program execution in a production environment." << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "Warning messages indicate a potential issue in the system. However, it can be handled or ignored." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "Error messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention." << std::endl;
}

