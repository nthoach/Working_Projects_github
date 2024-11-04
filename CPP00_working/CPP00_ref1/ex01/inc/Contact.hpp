/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:11:21 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/22 21:40:55 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>

class Contact
{
  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

  public:
	Contact(std::string firstName, std::string lastName, std::string nickName,
			std::string phoneNumber, std::string darkestSecret)
	{
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_nickName = nickName;
		this->_phoneNumber = phoneNumber;
		this->_darkestSecret = darkestSecret;
	};

	void getContactInfo(int index);
	void getContactDetail();
	std::string truncateString(std::string str, std::string::size_type maxlen);
};

#endif