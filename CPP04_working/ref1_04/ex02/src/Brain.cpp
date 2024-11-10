/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:47:34 by seozkan           #+#    #+#             */
/*   Updated: 2023/06/23 16:33:12 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
    std::string str[] = {"I have to eat", "I have to walk a little",
        "I have to find a place to sleep", "I have to drink water"};
    std::cout << "Brain constuctor called" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = str[std::rand() % 4];
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = brain._ideas[i];
    }
    return (*this);
}

void Brain::printIdeas() const
{
    std::cout << "Ideas-> " << "1: " << _ideas[0] << " 2: " << _ideas[1] << " 3: " << _ideas[2] << " ..." << std::endl;
}