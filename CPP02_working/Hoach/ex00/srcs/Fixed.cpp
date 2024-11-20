/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 17:36:40 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"


Fixed::Fixed(const int intVal)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intVal << _nfixed;
}

Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;	
	return(_value);
}

void Fixed::setRawBits (int const raw)
{
	_value = raw;
	std::cout << "setRawBits member fucnciton called" << std::endl;
}






