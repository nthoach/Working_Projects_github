/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:47:18 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/05 18:04:42 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) 
{
    PhoneBook   phonebook;
    std::string command;

    while (true) 
    {
        std::cout << "\033[36mSelect a command (ADD, SEARCH, EXIT): \033[0m";
        if (!std::getline(std::cin, command))
        {
            if (std::cin.eof())
                std::cout << "End of input detected. Exiting..." << std::endl;
            else
                std::cerr << "Error reading input. Exiting..." << std::endl;
            break;
        }
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);        
        if (command == "EXIT" || command == "E")
            break;
        else  if (command == "ADD" || command == "A")
            phonebook.addContact();
        else if (command == "SEARCH" || command == "S")
            phonebook.searchContact();
        else
            std::cout << "\033[31mINVALID COMMAND!\033[0m" << std::endl;
    }
    return 0;
}