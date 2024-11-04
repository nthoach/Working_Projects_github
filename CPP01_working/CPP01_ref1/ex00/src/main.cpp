/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:03 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/24 14:25:40 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main(void)
{
	std::cout << "--------------* StackMem *--------------" << std::endl;
	Zombie firstZombie("dale");
	firstZombie.announce();
	randomChump("hera");
	std::cout << "--------------* HeapMem *--------------" << std::endl;
	Zombie	*secondZombie;
	secondZombie = newZombie("spina");
	secondZombie->announce();
	delete(secondZombie);

	return (0);
}