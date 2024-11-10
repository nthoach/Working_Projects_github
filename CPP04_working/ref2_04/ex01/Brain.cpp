/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:02:29 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 12:43:37 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "🧠 Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Idea["+ std::to_string(i) + "]: 🌈";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "🧠 Brain copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "🧠 Brain destructor called" << std::endl;
	return ; 
}

Brain & Brain::operator =(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

std::string		Brain::getIdea(int i) const
{
	return this->_ideas[i];
}

void			Brain::setIdea(int i, std::string const & idea)
{
	this->_ideas[i] = idea;
}
