/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/12 15:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Harl.hpp"

int main() {
    Harl h;

    // Test all complaint levels
    std::cout << "Testing complain with 'debug' level:" << std::endl;
    h.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Testing complain with 'info' level:" << std::endl;
    h.complain("INFO");
    std::cout << std::endl;

    std::cout << "Testing complain with 'warning' level:" << std::endl;
    h.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Testing complain with 'error' level:" << std::endl;
    h.complain("ERROR");
    std::cout << std::endl;

    // Test an invalid level
    std::cout << "Testing complain with an invalid level:" << std::endl;
    h.complain("invalid_level");
    std::cout << std::endl;

    return 0;
}

