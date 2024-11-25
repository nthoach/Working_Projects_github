/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:07:55 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 14:20:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"
#include <sstream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time

Brain::Brain()
{
    std::string str_arr[] = {
        "I am barking", "I am eating", "I am sleeping",
        "I am drinking", "I am fighting", "I am looking boss",
        "I am looking for friend", "I dont like milk", "I am a  boss",
        "I am playing", "I am leaving home", "I am biting anyone" };
    
    const size_t str_arr_size = sizeof(str_arr) / sizeof(str_arr[0]);
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    for (size_t i = 0; i < SIZE; i++)
    {
        std::ostringstream oss;
        oss << i;
        std::string str = oss.str();
        _ideas[i] = "Idea[" + str + "]: " + str_arr[std::rand() % str_arr_size]; 
    }
 std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < SIZE; i++)
            _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain(void)
{
    std::cout << "Brain Destructor Called" << std::endl;
}

const std::string Brain::getIdea(int i) const
{
    return (_ideas[i]);
}

// Getter for mutable access
std::string Brain::getIdea(int i)
{
    return _ideas[i]; // Pointer to the array's first element
}

void			Brain::setIdea(int i, std::string const & idea)
{
	this->_ideas[i] = idea;
}