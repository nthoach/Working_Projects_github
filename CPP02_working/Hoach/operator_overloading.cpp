/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_overloading.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:34:26 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 18:43:42 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Operator Overloading in C++
Operator overloading in C++ allows you to define the behavior of operators (such as +, -, *, [], etc.) for user-defined types (such as classes). This means that you can redefine how operators work for your own objects, making them behave like built-in types for specific operations.

Operator overloading enhances the readability and usability of your code by enabling intuitive use of operators on custom types.

Key Points:
You cannot create new operators; you can only overload existing ones.
Operators are overloaded using the special member functions (such as operator+, operator-, operator[], etc.).
Operator overloading allows custom types (classes or structs) to be manipulated using the standard operators, making it easier to work with user-defined objects.

*/

#include <iostream>


class Complex
{
    private:
        double real, imag;

    public:
        Complex(double r = 0, double i = 0): real(r), imag(i) {}

        Complex operator+(const Complex& other)
        {
            return Complex(real + other.real, imag + other.imag);
        }
        
        void display() const
        {
            std::cout << real << "+" << imag << "i" << std::endl;
        }
};

int main()
{
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    Complex c3 = c1 + c2;

    std::cout << "C1: ";
    c1.display();
    std::cout << "C2: ";
    c2.display();
    std::cout << "C3: ";
    c3.display();
}