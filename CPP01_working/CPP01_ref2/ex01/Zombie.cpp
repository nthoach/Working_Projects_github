/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:47:58 by imontero          #+#    #+#             */
/*   Updated: 2023/12/09 19:00:45 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Nameless Zombie is born..." << std::endl;
	return ;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "🧟‍♂️ Zombie " << this->_name << " is born..." << std::endl;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "⚰ Zombie " << this->_name << " died..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}


void	Zombie::announce(void)
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
