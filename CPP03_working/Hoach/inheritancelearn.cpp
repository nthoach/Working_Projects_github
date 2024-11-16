/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritancelearn.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:38:52 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/15 14:58:50 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*

Inheritance in C++ is a feature that allows a child/derived class to inherit
properties and behaviors including data and funnction members from parent/based
class. 
5 types of inhertance:
1- Single inheritance: a child inherits from only oen paraent class
2- Multiple inheritance: a child inherites from more than on parent classes
3- Multilevel inheritance: a child -> parent -> grandparent
4- Hiearchical inheritance: Mullti child classes --> one parent
5- Hybrid Inheritance: Combination of more than one type of Inheritance

*/


#include <iostream>

class   Animal
{
    public:
        void eat()
        {
            std::cout << "Eating foods" << std::endl;
        }
};

class   Dog: public Animal
{
    public:
        void bark()
        {
            std::cout << "The dog barks" << std::endl;
        }
};

int main()
{
    Dog myDog;
    myDog.eat();
    myDog.bark();
    return 0;
}