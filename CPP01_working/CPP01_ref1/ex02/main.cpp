/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:26:07 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/28 17:44:53 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
    
	std::cout << "STR Memory Adress -> " << &str << std::endl;
    std::cout << "stringPTR Memory Adress -> " << stringPTR << std::endl;
    std::cout << "stringREF Memory Adress -> " << &stringREF << std::endl;
    std::cout << "STR Value -> " << str << std::endl;
    std::cout << "stringPTR Value -> " << *stringPTR << std::endl;
    std::cout << "stringREF Value -> " << stringREF << std::endl;
	return (0);
}
