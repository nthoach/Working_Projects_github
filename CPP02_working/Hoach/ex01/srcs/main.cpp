/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 17:40:47 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"
#include <iostream>


int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);

    std::cout << "\na is " << a.getRawBits() << " as fixed-point number" << std::endl;
    std::cout << "b is " << b.getRawBits() << " as fixed-point number" << std::endl;
    std::cout << "c is " << c.getRawBits() << " as fixed-point number" << std::endl;
    std::cout << "d is " << d.getRawBits() << " as fixed-point number\n" << std::endl;

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "\na is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer\n" << std::endl;

    return 0;
}


