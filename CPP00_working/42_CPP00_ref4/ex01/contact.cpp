/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:30 by imontero          #+#    #+#             */
/*   Updated: 2023/12/06 10:42:53 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//default constructor initialize with empty strings
Contact::Contact(): first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

//constructor
Contact::Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& secret):
    first_name(first), last_name(last), nickname(nick), phone_number(phone), darkest_secret(secret) {}

//Getters for practice. Not used
std::string Contact::getFirstName() const
{
    return (first_name);
}

std::string Contact::getLastName() const
{ 
    return (last_name); 
}

std::string Contact::getNickname() const
{
    return (nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (phone_number);
}

std::string Contact::getDarkestSecret() const
{
    return (darkest_secret);
}


void	Contact::displayContactIndex(int index) const
{
    std::cout << std::setw(10) << std::right << index << " | " 
                << std::setw(10) << std::right << truncateString(first_name, 10) << " | "
		        << std::setw(10) << std::right << truncateString(last_name, 10) << " | " 
                << std::setw(10) << std::right << truncateString(nickname, 10) 
                << std::endl;
}
    
void    Contact::displayContactInfo(int index) const
{
    std::cout << "Contact index: " << index << std::endl
            << "First name: " << this->first_name << std::endl
            << "Last name: " << this->last_name << std::endl
            << "Nickname: " << this->nickname << std::endl
            << "Telephone: " << this->phone_number << std::endl
            << "Darkest secret: " << this->darkest_secret << std::endl;
}

std::string	Contact::truncateString(const std::string& str, int width) const
{
	if (str.length() <= width) 
        return (str);
    return (str.substr(0, width - 1) + ".");
}