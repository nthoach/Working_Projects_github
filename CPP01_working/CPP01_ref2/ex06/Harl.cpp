/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:01:03 by imontero          #+#    #+#             */
/*   Updated: 2023/12/11 19:06:40 by imontero         ###   ########.fr       */
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
	int			i = 0;
	for (i ; i < 4; i++)
	{
		if (level == lvl[i])
			break ;
	}
	switch (i)
	{
		case 0:
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 1:
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 2:
			this->_warning();
			this->_error();
			break ;
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "Usage: ./harl [DEBUG, INFO, WARNING, ERROR]" << std::endl;
			break ;
	}
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

