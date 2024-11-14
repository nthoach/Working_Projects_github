/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:23:11 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 17:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _nfixed = 8;

public:
    // Constructors
    Fixed();                          // Default constructor
    Fixed(const int intVal);          // Constructor for integer
    Fixed(const float floatVal);      // Constructor for float
    Fixed(const Fixed& other);        // Copy constructor

    // Destructor
    ~Fixed();

    // Assignment operator
    Fixed& operator=(const Fixed& other);

    // Conversion functions
    float toFloat() const;
    int toInt() const;

    // Accessor functions
    int getRawBits() const;
    void setRawBits(int const raw);
};

// Overload for the << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
