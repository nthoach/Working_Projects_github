/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:42 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/04 16:28:09 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
	private: 
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact(std::string firstName, std::string lastName,std::string nickName,
				std::string phoneNumber,std::string darketSecret);
		~Contact(void);
		void addContact(int	index);
		void searchContact();
		std::string cutString(std::string str, std::string::size_type maxlen);
};

#endif
