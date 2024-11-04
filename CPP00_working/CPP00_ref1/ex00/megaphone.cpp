/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:32:52 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/21 21:58:18 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;
    
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;     
    else
    {
        j = 0;
        while (av[++j])
        {
            i = -1;
            while (av[j][++i])
                std::cout << (char)std::toupper(av[j][i]);
        }
        std::cout << std::endl;
    }
    return 0;
}
