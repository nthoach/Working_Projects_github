/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outptoverloading.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:58:24 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 19:23:23 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Complex
{
    private:
        double real, imag;

    public:
        Complex(double r = 0, double i = 0): real(r), imag(i) {}
        friend std::ostream& operator<<(std::ostream& os, const Complex& c)
        {
            os << c.real << " + " << c.imag << "i";
            return os; 
        }
};

int main()
{
    Complex c1(3.5, 2.5);
    std::cout << "Complex number: " << c1 << std::endl;
    return 0;

}