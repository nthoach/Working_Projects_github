/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:53:12 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/29 16:47:56 by seozkan          ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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