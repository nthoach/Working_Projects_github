/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:05:55 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 13:07:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & copy);
		virtual ~Ice(void);

		Ice &	operator=(Ice const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
