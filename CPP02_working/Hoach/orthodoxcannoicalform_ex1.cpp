/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthodoxcannoicalform_ex1.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:09:19 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 16:09:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
In C++98, the "orthodox canonical class form" (also known as the "Rule of Three") specifies a pattern for creating classes that handle dynamic resources. When a class manages resources such as dynamically allocated memory or file handles, it should define three special member functions:
0. Constructor (i.e., Myclass("Hello"))
1. Destructor (i.e., ~Myclass): To release the resources when the object goes out of scope.
2. Copy Constructor (i.e., Myclass obj2 = obj1): To create a deep copy of the object.
3. Copy Assignment Operator (i.e., obj2 = obj1): To assign one object to another while ensuring a deep copy of resources.
*/


#include <iostream>
#include <cstring>

class Myclass
{
	private:
		char* data;
	
	public:
		// Constructor
		Myclass(const char* str = "")
		{
			data = new char[std::strlen(str) + 1];
			std::strcpy(data, str);
			std::cout << "Constructor called. \n";
		}

		// Destructor
		~Myclass()
		{
			delete[] data;
			std::cout << "Destructor called\n";
		}
		// Copy Constructor Myclass obj2 = obj1
		Myclass(const Myclass& other)
		{
			data = new char[std::strlen(other.data) + 1];
			std::strcpy(data, other.data);
			std::cout << "Copy Constructor Called\n";
		}
		// Copy Assignment Operator i.e., object2 = object1
		Myclass& operator=(const Myclass& other)
		{
			if (this != &other)
			{
				delete[] data;
				data = new char[std::strlen(other.data) + 1];
				std::strcpy(data, other.data);
			}
			std::cout << "Copy Assignment Operator called\n";
			return *this;
		}
		// A method to display the data
		void show() const
		{
			std::cout << "Data: " << data << std::endl;
		}
};

int main()
{
	Myclass obj1("Xin chao"); //Constructor with input
	Myclass obj2 = obj1; // Copy constructor
	Myclass obj3; //Constructor without input
	obj3 = obj1; //Copy assignment operator

	obj1.show();
	obj2.show();
	obj3.show();

	return 0;
}
