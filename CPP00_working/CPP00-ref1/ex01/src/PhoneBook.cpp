/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:12:07 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/22 22:20:57 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	convertStringToInt(const std::string &str)
{
	int	value;

	std::istringstream iss;
	iss.str(str);
	value = 0;
	iss >> value;
	return (value);
}

void PhoneBook::addContact()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	if (contacts.size() >= 8)
	{
		contacts.erase(contacts.begin());
	}
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	Contact newContact(firstName, lastName, nickName, phoneNumber,
			darkestSecret);
	contacts.push_back(newContact);
}

void PhoneBook::searchContact()
{
	std::string input;
	size_t index;

	if (contacts.empty())
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "\033[31mIndex" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << "|\033[0m" << std::endl;

	for (size_t i = 0; i < contacts.size(); i++)
	{
		contacts[i].getContactInfo(i + 1);
	}

	while (true)
	{
		std::cout << "\033[36mPlease select index for more detail\033[0m" << std::endl;
		std::getline(std::cin, input);

		index = convertStringToInt(input);
		if (index < 1 || index > contacts.size())
		{
			std::cout << ("You have entered an invalid index.") << std::endl;
			continue ;
		}
		Contact contact = contacts[index - 1];
		contact.getContactDetail();
		break ;
	}
}