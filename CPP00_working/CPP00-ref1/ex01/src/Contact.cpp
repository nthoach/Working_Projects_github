/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:02:23 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/22 22:56:16 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::truncateString(std::string str,
	std::string::size_type maxlen)
{
	if (str.length() <= maxlen)
		return (str);
	else
		return (str.substr(0, maxlen - 1) + ".");
}

void Contact::getContactInfo(int index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncateString(_firstName, 10) << "|";
	std::cout << std::setw(10) << truncateString(_lastName, 10) << "|";
	std::cout << std::setw(10) << truncateString(_nickName,10) << "|" 
		<< std::endl;
}

void Contact::getContactDetail()
{
	std::cout << "| " << "Firstname " << _firstName << " |" << std::endl;
	std::cout << "| " << "Firstname " << _firstName << " |" << std::endl;
	std::cout << "| " << "Lastname " << _lastName << " |" << std::endl;
	std::cout << "| " << "Nickname " << _nickName << " |" << std::endl;
	std::cout << "| " << "Phonenumber " << _phoneNumber << " |" << std::endl;
	std::cout << "| " << "Darkestsecret " << _darkestSecret << " |" 
		<< std::endl;
}
