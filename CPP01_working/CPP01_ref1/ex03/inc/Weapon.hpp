/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:03:56 by seozkan           #+#    #+#             */
/*   Updated: 2023/05/28 19:45:03 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	std::string const &getType();
	void setType(std::string type);
};

#endif