/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:35 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/04 19:16:09 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::Phonebook(void)
{
	_contactCount = 0;
	return ;
}

PhoneBook::~Phonebook(void)
{
	return ;
}

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

int PhoneBook::addContact()
{
	std::string	input;
	if (_contactCount == 8)
		std::cout << "PhoneBook is full, the newest contact will replace the oldest one." << std::endl;
	int index = _contactCount % 8;
	std::cout << "Contact #" << index << std::endl;

	std::string first, last, nick, phone, secret;
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, first)) 
		return (0);
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, last))
		return (0);
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nick))
		return (0);
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phone))
		return (0);
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, secret))
		return (0);
	// If empty input or only spaces. ask again
	if (first.empty() || isOnlySpaces(first) || last.empty() || isOnlySpaces(last) || nick.empty() || 
		isOnlySpaces(nick) || phone.empty() || isOnlySpaces(phone) || secret.empty() || isOnlySpaces(secret))
	{
		std::cout << "Invalid input. Empty Field(s)." << std::endl;
		return (0);
	}
	if (!isValidName(first) || !isValidName(last))  //check if names only contain letters or ' '
	{
		std::cout << "Invalid first name or last name. They should contain only letters." << std::endl;
		return (0);
	}	
	if (!isValidPhoneNumber(phone)) //check if phonenumbers only contain numbers or a '+' or ' '
	{
		std::cout << "Invalid phone number. It should contain only digits and/or '+'." << std::endl;
		return (0);
	}
	Contact	newContact(first, last, nick, phone, secret);
	_contacts[index] = newContact;
	_contactCount++;
}

void PhoneBook::searchContact() const
{
	std::string	input;
	
	if (!_contactCount)
	{
		std::cout << "\033[31mEmpty Phonebook.\033[0m]" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "\033[31mIndex" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << "|\033[0m" << std::endl;

	int index = -1;
	while (++index < _contactCount)
		_contacts[index].displayContact(_contacts[index], i);
	while (true)
	{
		std::cout << "\033[36mPlease Emter Contact Index to Search:\033[0m" << std::endl;
		while (!(std::getline(std::cin, input)) || input.length() > 1 || input.compare("0") < 0
				|| input.compare("8") > 0 || (std::atoi(input.c_str()) > _contactCount))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Exiting phonebook..." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("0") < 0 || input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "\033[31mEnter Index Number from [1 - 8]:\033[0m\n";
			}
			else if (std::atoi(input.c_str())  > this->_contactCount)
			{
				std::cout << "\033[33mPhone Book has only " << _contactCount << " Contacts saved.\033[0m" << std::endl;
				std::cin.clear();
				std::cout << "Enter Index Number from [0 - " << _contactCount << "]: ";
			}
		}
		i = std::atoi(input.c_str());;
		//if (i < 1 || i > _contactCount)
		//{
		//	std::cout << ("You have entered an invalid index.") << std::endl;
		//	continue ;
		//}
		_contacts[i - 1].printContact(_contacts[i-1], i -1);
		break ;
	}
}