/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:48:59 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 17:07:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	AAnimal
{
	protected:
		std::string	type;
	
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal(void);

		AAnimal & operator =(AAnimal const &inst2);

		std::string	getType() const;
		void  		setType(std::string type);
		virtual std::string	getIdea(int i) const;
		virtual void		makeSound(void) const = 0;
		
};



#endif
