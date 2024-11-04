/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 08:47:45 by imontero          #+#    #+#             */
/*   Updated: 2023/12/09 17:58:35 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "1st:" << std::endl;
	
	/*
		Create an instance and call announce method
	*/
	Zombie instA("Antxon");
	instA.announce();

	std::cout << std::endl;
	std::cout << "2st:" << std::endl;
	
	/* 
		Create an instance assigning the return of newZombie function
		which allocates memory for an object and returns it:
		then call announce method
	*/
	Zombie	*instB = newZombie("Potxolo");
	instB->announce();
	
	std::cout << std::endl;
	std::cout << "2st:" << std::endl;

	/* 
		Calls randomChum function which instanciate a Zombie object with 
		the name passed as parameter and calls announce method.
	*/
	randomChump("Joserra");
	std::cout << std::endl;
	
	/* 
		Destructors are automatically called except for the allocated 
		instance which needs to be freed.
	*/
	delete instB;
	
	return(0);
}