/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:23:11 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/10 14:08:17 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie( std::string name );
		~Zombie( );
		void announce( void );
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif