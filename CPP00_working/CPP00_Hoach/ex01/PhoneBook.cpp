/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:35 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 16:15:41 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_contactCount = 0;
}

PhoneBook::~PhoneBook() {}

static bool isOnlySpaces(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            return (false);
    }
    return (true);
}

void read_fields(std::string* first, std::string* last, 
				std::string* nick, std::string* phone, std::string* secret)
{
	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, *first)) 
		return;
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, *last))
		return;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, *nick))
		return;
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, *phone))
		return;
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, *secret))
		return;
}

void PhoneBook::addContact()
{
	if (_contactCount == 8)
		std::cout << "\033[31mPhoneBook is full, the newest contact will replace the oldest one.\033[0m" << std::endl;
	int index = _contactCount % 8;
	std::cout << "Contact #" << index + 1 << std::endl;

	std::string first, last, nick, phone, secret;
	read_fields(&first, &last, &nick, &phone, &secret);

	if (first.empty() || isOnlySpaces(first) || last.empty() || isOnlySpaces(last) || nick.empty() || 
		isOnlySpaces(nick) || phone.empty() || isOnlySpaces(phone) || secret.empty() || isOnlySpaces(secret))
	{
		std::cout << "\033[31mINVALIDinput. EMPTY Field(s).\033[0m" << std::endl;
		return;
	}
	Contact	newContact(first, last, nick, phone, secret);
	_contacts[index] = newContact;
	_contactCount++;
}


void PhoneBook::print_table(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	int index = -1;
	while (++index < this->_contactCount)
		this->_contacts[index].displayContact(_contacts[index], index);
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::print_contact(void)
{
	std::string	input;
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

void PhoneBook::searchContact()
{
	if (!_contactCount)
	{
		std::cout << "\033[31mEmpty Phonebook.\033[0m" << std::endl;
		return ;
	}
    print_table();
	print_contact();
}