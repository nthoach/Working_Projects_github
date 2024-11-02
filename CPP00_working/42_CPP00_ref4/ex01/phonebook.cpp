/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:19:48 by codespace         #+#    #+#             */
/*   Updated: 2023/11/08 21:20:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(): contact_count(0) {}

/*  add a contact if there is space
    repaces oldest contact if not    
*/
void    Phonebook::addContact(const Contact& contact)
{
    if (contact_count < 8) 
    {
        contacts[contact_count] = contact;
        contact_count++;
    } 
    else 
    {
        for (int i = 7; i > 0; i--)
            contacts[i] = contacts[i - 1];
         contacts[0] = contact;
    }
}
/* Displays all contacts header + every contact index
in the required format. 10 wide. Right aligned */
void    Phonebook::displayHeader() const
{
    std::cout << std::setw(10) << std::right << "Index" << " | " 
          << std::setw(10) << std::right << "First Name" << " | " 
          << std::setw(10) << std::right << "Last Name" << " | " 
          << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    for (int i = 0; i < contact_count; ++i)
        contacts[i].displayContactIndex(i);
}