/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:02:42 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/05 16:59:07 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private: 
		Contact _contacts[8];
		int		_contactCount;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact();
		void	searchContact();	
};

#endif
