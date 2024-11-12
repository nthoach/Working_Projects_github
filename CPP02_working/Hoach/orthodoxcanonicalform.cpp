/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthodoxcanonicalform.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:35:03 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 19:42:57 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

In C++98, an "Orthodox Canonical Class Form" (or simply, a "Canonical Class") follows 
a set of rules ensuring proper resource management and consistent behavior. 
The canonical form includes a specific set of functions:
In C++98, an "Orthodox Canonical Class Form" (or simply, a "Canonical Class") follows a set of rules ensuring proper resource management and consistent behavior. The canonical form includes a specific set of functions:

1. Constructor
2. Copy Constructor
3. Destructor
4. Copy Assignment Operator
These four ensure that a class can safely manage its resources, copy itself, and 
clean up without memory leaks or undefined behavior. Here are a few examples of 
canonical classes in C++98, each demonstrating the canonical form's principles.
These four ensure that a class can safely manage its resources, copy itself, and
 clean up without memory leaks or undefined behavior. Here are a few examples of 
 canonical classes in C++98, each demonstrating the canonical form's principles.

*/

#include <iostream>
#include <cstring>

class Array
{
    private: 
        int *data;
        int  size;

    public:
        // Constructor
        Array(int s): size(s), data(new int[s])
        {
            std::memset(data, 0, sizeof(int) * size);
        }
        // Copy Constructor
        Array(const Array &other): size(other.size), data(new int[other.size])
        {
            std::memset(data, other.data, sizeof(int) * size);
        }
}