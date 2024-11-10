/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:01:30 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 16:36:12 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_materias[4];
	
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & copy);
		~Character(void);
		Character &	operator=(Character const & rhs);

		std::string const &	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
