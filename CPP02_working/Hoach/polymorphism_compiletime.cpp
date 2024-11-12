/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:56:10 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 18:09:51 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

In C++98, polymorphism refers to the ability of a function, method, or operator to behave differently based on the type of the object it is acting upon. It is one of the fundamental principles of Object-Oriented Programming (OOP) and is often categorized into two types: compile-time polymorphism (also known as static polymorphism) and runtime polymorphism (dynamic polymorphism).

Types of Polymorphism in C++98
Compile-time Polymorphism (Static Binding)
Achieved via function overloading or operator overloading.
Runtime Polymorphism (Dynamic Binding)
Achieved via inheritance and virtual functions.
Types of Polymorphism in C++98
Compile-time Polymorphism (Static Binding)
Achieved via function overloading or operator overloading.
Runtime Polymorphism (Dynamic Binding)
Achieved via inheritance and virtual functions.

*/

#include <iostream>

class Printer
{
    public:
        void print(int i)
        {
            std::cout << "Printing integer: " << i << std::endl;
        }

        void print (double d)
        {
            std::cout << "Printing double: " << d << std::endl;
        }

        void print (const char *str)
        {
            std::cout << "Printing string: " << str << std::endl;
        }
};

int main()
{

    Printer p;
    p.print(10);
    p.print(3.1412);
    p.print("Hello!");
    
    return 0;
}