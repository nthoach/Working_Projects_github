/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:48:59 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:38:25 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		Animal & operator =(Animal const &inst2);

		std::string	getType() const;
		void  		setType(std::string type);
		virtual void		makeSound(void) const;
		
};



#endif
