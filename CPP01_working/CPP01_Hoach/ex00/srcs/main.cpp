/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:33 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/15 11:18:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main(void)
{
std::cout << "---------* Creating Zombie in StackMemory *----------" << std::endl;
Zombie zombie0;
Zombie zombie1("Model X");
zombie1.announce();

randomChump("Model Y");

std::cout << "---------* Creating Zombie in HeapMemory *------------"<< std::endl;
Zombie *zombie3; 
zombie3 = newZombie("Model Z");
zombie3->announce();
delete(zombie3);

return 0;	
}
