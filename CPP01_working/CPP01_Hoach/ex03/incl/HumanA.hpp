/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:23:11 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 17:08:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMAN_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon;
		HumanA( void );
		HumanA(std::string name);
	public:
		HumanA(std::string name, Weapon& weapon);
		HumanA( Weapon& weapon);
		~HumanA( );
		void attack( void );
};

#endif