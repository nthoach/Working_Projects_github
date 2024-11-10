/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:25:30 by imontero          #+#    #+#             */
/*   Updated: 2023/12/21 16:30:30 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
	
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		virtual ~MateriaSource(void);
		MateriaSource &	operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);

};

#endif
