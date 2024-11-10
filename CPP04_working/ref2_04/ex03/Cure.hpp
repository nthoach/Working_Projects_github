/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:13:32 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 16:30:51 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & copy);
		virtual ~Cure(void);
		Cure &	operator=(Cure const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};


#endif
