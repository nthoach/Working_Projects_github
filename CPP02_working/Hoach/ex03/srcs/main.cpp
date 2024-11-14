/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/14 11:41:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"
#include "../incl/Point.hpp"
#include <iostream>


int main()
{
    // Create points
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);
    Point pointInside(2, 2);
    Point pointOutside(5, 5);
    
    // Test points
    std::cout << "Is pointInside inside the triangle? " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Is pointOutside inside the triangle? " << bsp(a, b, c, pointOutside) << std::endl;

    return 0;
}


