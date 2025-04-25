<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 14:40:02 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:44:02 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:33 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

#include "../incl/Bureaucrat.hpp"

int main()
{
<<<<<<< HEAD
    std::cout << "\n\n=====================" << std::endl;
    
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.Promote(); // 2 --> 1
        std::cout << "After increment: " << a << std::endl;
        a.Promote();  // 1--> 0 should throw
=======
	std::cout << "\n\n==================== Bureaucrat ====================" << std::endl;
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.promote();
        std::cout << "After promotion: " << a << std::endl;
        a.demote();  // should throw
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

<<<<<<< HEAD
    std::cout << "\n";
    try {
        Bureaucrat b("Bob", 151);  // 151 > 150 invalid initial grade
        std::cout << b << std::endl;
=======
    try {
        Bureaucrat b("Bob", 151);  // invalid initial grade
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

<<<<<<< HEAD
    std::cout << "\n";
    try {
        Bureaucrat c("Charlie", 149);
        std::cout << c << std::endl;
        c.Demote(); // 149 -> 150
        std::cout << "After decrement: " << c << std::endl;
        c.Demote();  // 150 -> 151 should throw
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
=======
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
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
    return 0;
}