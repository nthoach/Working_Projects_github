/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 16:53:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of the string:" << &str << std::endl;
	std::cout << "Value of the pointer:" << stringPTR << std::endl;
	std::cout << "Address of the reference:" << &stringREF << std::endl;
	
	std::cout << "Value of the string:" << str << std::endl;
	std::cout << "Value pointed by the pointer:" << *stringPTR << std::endl;
	std::cout << "Value of the reference:" << stringREF << std::endl;
	return (0);
}
