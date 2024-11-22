/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:30:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 11:23:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/DiamondTrap.hpp"

int main()
{
	std::cout << std::endl << std::endl;
		DiamondTrap DiaClap("DiaCLAP");
        DiamondTrap DiaTrap("DiaTRAP");
		std::cout << std::endl;
		DiaClap.showStatus();
        DiaTrap.showStatus();
		DiaClap.setDamage(30);
		DiaTrap.setDamage(110);

		std::cout << std::endl;
        DiaClap.attack(DiaTrap.getName());
        DiaTrap.takeDamage(DiaClap.getDamage()); 
		DiaClap.showStatus();
        DiaTrap.showStatus();

    DiaClap.whoAmI();
    DiaTrap.whoAmI();
    return 0;
}
