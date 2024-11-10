/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:14:10 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 16:40:08 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string		_type;
		
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & rhs);

		std::string const &	getType(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

};





#endif
