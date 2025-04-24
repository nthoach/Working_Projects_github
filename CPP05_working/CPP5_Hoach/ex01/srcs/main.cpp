/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:33 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/Bureaucrat.hpp"

int main()
{
	std::cout << "\n\n==================== Bureaucrat ====================" << std::endl;
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.promote();
        std::cout << "After promotion: " << a << std::endl;
        a.demote();  // should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 151);  // invalid initial grade
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 149);
        std::cout << c << std::endl;
        c.demote();
        std::cout << "After demotion: " << c << std::endl;
        c.demote();  // should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "==================== Bureaucrat ====================\n" << std::endl;
    return 0;
}