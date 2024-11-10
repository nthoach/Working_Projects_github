/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 17:08:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address:" << &str << std::endl;
	std::cout << "Address:" << stringPTR << std::endl;
	std::cout << "Address:" << &stringREF << std::endl;
	
	std::cout << "Value:" << str << std::endl;
	std::cout << "Value:" << *stringPTR << std::endl;
	std::cout << "Value:" << stringREF << std::endl;
	return (0);
}
