/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/15 12:48:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Harl.hpp"

Harl::Harl() 
{
	std::cout << "Harl constructed." << std::endl;
}

Harl::~Harl() 
{
	std::cout << "Harl deconstructed." << std::endl;
}

void Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle \
 	-specialketchup burger. I really do!" << std::endl; 
}

void Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
	enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl; 
}

void Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
	years whereas you started working here since last month." << std::endl; 
}

void Harl::_error()
{
 std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
}

void Harl::complain( std::string level )
{
	std::string lv[4] = {"DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*ptrf[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	int index = 0;
	while (level != lv[index] && index < 4)
		index++;
	
	switch (index)
	{
		case 0: 
			(this->*ptrf[0])();
			(this->*ptrf[1])();
			(this->*ptrf[2])();
			(this->*ptrf[3])();
			return;
		case 1:
			(this->*ptrf[1])();
			(this->*ptrf[2])();
			(this->*ptrf[3])();
			return;
		case 2:
			(this->*ptrf[2])();
			(this->*ptrf[3])();
			return;
		case 3:
			(this->*ptrf[3])();
			return;
		default:
	        std::cout << "Invalid Level." << std::endl;
            return;
    }
}
