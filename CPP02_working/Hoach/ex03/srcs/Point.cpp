/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:38:28 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 11:38:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Point.hpp"
#include "../incl/Fixed.hpp"

// Constructors
Point::Point() : x(0), y(0) {
  //  std::cout << "Default constructor called" << std::endl;
}

Point::Point(float xVal, float yVal) : x(xVal), y(yVal) {
 //   std::cout << "Constructor with parameters called" << std::endl;
 //std::cout << x << y << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
  //  std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Point::~Point() {
  //  std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Point& Point::operator=(const Point& other) {
   // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
      // Fixed attributes are constant, so no need to assign.
    }
    return *this;
}

// Getter functions
Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

// Helper function for area of triangle
Fixed area(Point const a, Point const b, Point const c)
{
    return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}

// BSP function
bool bsp(Point const a, Point const b, Point const c, Point const m) {

  Fixed A = area(a, b, c);

  Fixed A1 = area(m, b, c);
   Fixed A2 = area(a, m, c);
  Fixed A3 = area(a, b, m);

  bool allPositive = (A1 > 0 && A2 > 0 && A3 > 0);
  bool allNegative = (A1 < 0 && A2 < 0 && A3 < 0);
  bool onEdge = (A1 == 0 && A2 == 0 && A3 == 0);

    return allPositive || allNegative || onEdge;

    // return abs(A.getRawBits()) == abs(A1.getRawBits()) + abs(A2.getRawBits()) + abs(A3.getRawBits()) ;
}
