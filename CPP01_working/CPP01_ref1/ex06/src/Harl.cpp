/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:31:14 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/29 19:23:11 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    _str[0] = "DEBUG";
    _str[1] = "INFO";
    _str[2] = "WARNING";
    _str[3] = "ERROR";

	_p[0] = &Harl::debug;
	_p[1] = &Harl::info;
	_p[2] = &Harl::warning;
	_p[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

std::string Harl::getStr(int i)
{
	return _str[i];
}

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < 4; i++) {
		if (level == _str[i]) {
			(this->*_p[i])();
			return;
		}
	}
	std::cout << "\033[0;35mInput Error!\033[0m" << std::endl;
}