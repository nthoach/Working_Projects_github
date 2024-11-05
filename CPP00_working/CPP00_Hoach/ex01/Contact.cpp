/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:35 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/05 18:15:01 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, 
const std::string& secret): _firstName(first), _lastName(last), _nickName(nick), _phoneNumber(phone), _darkestSecret(secret) {}

void Contact::displayContact(Contact contact, int i)
{
	std::cout << "|" << std::setw(10) << i + 1 << "|";
	if (contact._firstName.size() > 10)
		std::cout << std::string(contact._firstName.begin(), contact._firstName.begin() + 9) << '.';
	else
		std::cout << std::setw(10) << contact._firstName;
	std::cout << "|";
	if (contact._lastName.size() > 10)
		std::cout << std::string(contact._lastName.begin(), contact._lastName.begin() + 9) << '.';
	else
		std::cout << std::setw(10) << contact._lastName;
	std::cout << "|";
	if (contact._nickName.size() > 10)
		std::cout << std::string(contact._nickName.begin(), contact._nickName.begin() + 9) << '.';
	else
		std::cout << std::setw(10) << contact._nickName;
	std::cout << "|\n";
}

void Contact::printContact(Contact contact, int i)
{
	std::cout << "Contact # " << i + 1 << std::endl;
	std::cout << "First name: " << contact._firstName << std::endl;
    std::cout << "Last name: " << contact._lastName << std::endl;
    std::cout << "Nickname: " << contact._nickName << std::endl;
    std::cout << "Phone number: " << contact._phoneNumber << std::endl;
    std::cout << "Darkest secret: " << contact._darkestSecret << std::endl;
}
