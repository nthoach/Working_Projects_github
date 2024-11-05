/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:35 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/05 18:18:22 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_contactCount = 0;
}

PhoneBook::~PhoneBook() {}

static bool isValidName(const std::string& name)
{
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        char c = name[i];
        if (!std::isalpha(c) && c != ' ')
            return (false);
    }
    return (true);
}

static bool isValidPhoneNumber(const std::string& phone) 
{
    for (std::string::size_type i = 0; i < phone.length(); ++i) 
    {
        char c = phone[i];
        if (!std::isdigit(c) && c != '+')
            return (false);
    }
    return (true);
}


static bool isOnlySpaces(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return (false);
    }
    return (true);
}

void PhoneBook::addContact()
{
	std::string	input;
	if (_contactCount == 8)
		std::cout << "\033[31mPhoneBook is full, the newest contact will replace the oldest one.\033[0m" << std::endl;
	int index = _contactCount % 8;
	std::cout << "Contact #" << index + 1 << std::endl;

	std::string first, last, nick, phone, secret;
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, first)) 
		return;
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, last))
		return;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nick))
		return;
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phone))
		return;
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, secret))
		return;
	if (first.empty() || isOnlySpaces(first) || last.empty() || isOnlySpaces(last) || nick.empty() || 
		isOnlySpaces(nick) || phone.empty() || isOnlySpaces(phone) || secret.empty() || isOnlySpaces(secret))
	{
		std::cout << "\033[31mINVALIDinput. EMPTY Field(s).\033[0m" << std::endl;
		return;
	}
	//if (!isValidName(first) || !isValidName(last))
	//{
	//	std::cout << "Invalid first name or last name. They should contain only letters." << std::endl;
	//	return;
	//}	
	//if (!isValidPhoneNumber(phone))
	//{
	//	std::cout << "Invalid phone number. It should contain only digits and/or '+'." << std::endl;
	//	return ;
	//}
	Contact	newContact(first, last, nick, phone, secret);
	_contacts[index] = newContact;
	_contactCount++;
}

void PhoneBook::searchContact()
{
	std::string	input;

	if (!_contactCount)
	{
		std::cout << "\033[31mEmpty Phonebook.\033[0m]" << std::endl;
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    
	int index = -1;
	while (++index < _contactCount)
		_contacts[index].displayContact(_contacts[index], index);
	std::cout << "|-------------------------------------------|" << std::endl;

	while (true)
	{
		std::cout << "\033[36mEnter Contact Index to Search:\033[0m" << std::endl;
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("1") < 0
				|| input.compare("9") > 0 || (std::atoi(input.c_str()) > _contactCount))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Exiting phonebook..." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("1") < 0 || input.compare("9") > 0)
			{
				std::cin.clear();
				std::cout << "\033[31mEnter Index Number from [1 - " << _contactCount << "]: \033[0m\n";
			}
			else if (std::atoi(input.c_str())  > _contactCount)
			{
				std::cout << "\033[36mPhone Book has only " << _contactCount << " Contacts saved.\033[0m" << std::endl;
				std::cin.clear();
				std::cout << "\033[31mEnter Index Number from [1 - " << _contactCount << "]: \033[0m\n";
			}
		}
		int i = std::atoi(input.c_str());
		if (i < 1 || i > _contactCount)
		{
			std::cout << ("You have entered an invalid index.") << std::endl;
			continue ;
		}
		_contacts[i - 1].printContact(_contacts[i-1], i -1);
		break ;
	}
}