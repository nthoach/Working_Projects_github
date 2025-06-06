/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 15:52:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

int main()
{
    std::cout << "\n\n=====================" << std::endl;
    
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.promote(); // 2 --> 1
        std::cout << "After increment: " << a << std::endl;
        a.promote();  // 1--> 0 should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";
    try {
        Bureaucrat b("Bob", 151);  // 151 > 150 invalid initial grade
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";
    try {
        Bureaucrat c("Charlie", 149);
        std::cout << c << std::endl;
        c.demote(); // 149 -> 150
        std::cout << "After decrement: " << c << std::endl;
        c.demote();  // 150 -> 151 should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n";

    Bureaucrat c("Charlie", 150);
    std::cout << c << std::endl;
    Bureaucrat *d = new Bureaucrat();
    std::cout << *d << std::endl;
    *d = c;
    std::cout << *d << std::endl;
    delete d;
    
    std::cout << "=====================\n\n" << std::endl;
    return 0;
}