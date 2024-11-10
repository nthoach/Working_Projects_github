/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:20:15 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:43:53 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

		WrongAnimal & operator =(WrongAnimal const &rhs);

		std::string	getType() const;
		void  		setType(std::string type);
		virtual void		makeSound(void) const;
		
};

#endif
