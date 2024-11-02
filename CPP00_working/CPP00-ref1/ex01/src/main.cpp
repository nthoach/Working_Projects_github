/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:12:34 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/22 22:21:52 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	std::string input;
	while (true)
	{
		std::cout << "\033[36mPlease enter a command (ADD, SEARCH, EXIT): \033[0m";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (input == "EXIT")
			break ;
		else
		{
			std::cout << "\033[31mWrong Choise!\033[36m" << std::endl;
		}
	}
	return (0);
}
