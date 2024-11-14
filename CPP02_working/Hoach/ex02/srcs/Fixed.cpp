/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/14 11:31:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int intVal)
{
    std::cout << "Int constructor called" << std::endl;
    _value = intVal << _nfixed;  // Convert to fixed-point
}

// Float constructor
Fixed::Fixed(const float floatVal)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(floatVal * (1 << _nfixed));  // Convert to fixed-point
	
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Convert fixed-point to float
float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _nfixed);
}

// Convert fixed-point to int
int Fixed::toInt() const {
    return _value >> _nfixed;
}

// Accessor functions
int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = _value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = _value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result._value = (_value * other._value) >> _nfixed;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    Fixed result;
    result._value = (_value << _nfixed) / other._value;
    return result;
}

// Increment/decrement operators
Fixed& Fixed::operator++() {  // Pre-increment
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {  // Post-increment
    Fixed temp = *this;
    _value++;
    return temp;
}

Fixed& Fixed::operator--() {  // Pre-decrement
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {  // Post-decrement
    Fixed temp = *this;
    _value--;
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Overload the << operator to output a floating-point representation
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
