/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polymorphism_runtime.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:56:10 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 18:29:47 by honguyen         ###   ########.fr       */
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

In runtime polymorphism, virtual functions are used to allow derived classes to provide
their own implementation of a function, which can then be invoked through a pointer or 
reference to a base class. The decision of which method to call is made at runtime, 
hence the term dynamic binding.
*/

#include <iostream>

class Animal
{
    public:
        virtual void sound()
        {
            std::cout << "Animal makes a sound" << std::endl;
        }
        virtual ~Animal()
        {
            std::cout << "Animal Destructed." << std::endl;
        }
};

class Dog: public Animal
{
    public:
        void sound()
        {
            std::cout << "Dog barks" << std::endl;
        }
        ~Dog()
        {
            std::cout << "Mr Dog destructed." << std::endl;
        }
};

class Cat: public Animal
{
    public:
        void sound()
        {
            std::cout << "Cat meows" << std::endl;
        }
         ~Cat()
        {
            std::cout << "Miss Cat destructed." << std::endl;
        }
};

int main()
{

    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->sound();
    animal2->sound();

    delete animal1;
    delete animal2;    

    return 0;
}

