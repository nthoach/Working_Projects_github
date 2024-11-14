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
    if (this != &other) {
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
Fixed area(Point const a, Point const b, Point const c) {
    return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}

// BSP function
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate the area of the full triangle (a, b, c)
    Fixed A = area(a, b, c);

    // Calculate the areas of the sub-triangles formed by the point and the triangle vertices
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    // The point is inside the triangle if the sum of the areas of the sub-triangles is equal to the area of the triangle
    return A == A1 + A2 + A3;
}
