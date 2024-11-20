/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 17:56:32 by honguyen         ###   ########.fr       */
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
    Point pointOutside(2, 4 - 1/256);
    
    // Test points
    std::cout << "Is pointInside inside the triangle? " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Is pointOutside inside the triangle? " << bsp(a, b, c, pointOutside) << std::endl;

    return 0;
}


