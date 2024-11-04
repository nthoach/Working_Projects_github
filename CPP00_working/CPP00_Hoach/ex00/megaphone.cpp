/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:47:18 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/03 09:26:20 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int agc, char **agv)
{
    if (agc > 1)
    {
        int i = 0;
        while (agv[++i])
        {
            int j = -1;
            while (agv[i][++j])
                std::cout << (char)std::toupper(agv[i][j]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);    
}
