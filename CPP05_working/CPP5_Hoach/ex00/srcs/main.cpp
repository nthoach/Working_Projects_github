/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/18 17:56:31 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.increGrade();
        std::cout << "After increment: " << a << std::endl;
        a.increGrade();  // should throw
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
        c.decreGrade();
        std::cout << "After decrement: " << c << std::endl;
        c.decreGrade();  // should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}