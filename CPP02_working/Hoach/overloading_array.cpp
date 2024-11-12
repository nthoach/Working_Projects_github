/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overloading_array.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:28:31 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 19:30:02 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Array
{
private:
    int data[10];

public:
    Array() 
    {
        for (int i = 0; i < 10; ++i) {
            data[i] = i + 1;
        }
    }

    // Overload the [] operator
    int& operator[](int index) 
    {
        return data[index];
    }

    const int& operator[](int index) const
    {
        return data[index];
    }
};

int main()
{
    Array arr;
    arr[3] = 42;  // Use overloaded [] operator to set value

    for (int i = 0; i < 10; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;  // Use overloaded [] operator to get value
    }

    return 0;
}