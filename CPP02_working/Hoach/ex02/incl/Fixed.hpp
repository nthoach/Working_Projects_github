/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:33:21 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/17 15:33:26 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
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

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/decrement operators
    Fixed& operator++();      // Pre-increment
    Fixed operator++(int);    // Post-increment
    Fixed& operator--();      // Pre-decrement
    Fixed operator--(int);    // Post-decrement

    // Static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Accessor functions
    int getRawBits() const;
    void setRawBits(int const raw);
};

// Overload for the << operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
