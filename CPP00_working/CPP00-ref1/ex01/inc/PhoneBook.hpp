/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:11:06 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/22 22:12:58 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>
#include <vector>

class PhoneBook
{
  private:
	std::vector<Contact> contacts;

  public:
	void addContact();
	void searchContact();
};