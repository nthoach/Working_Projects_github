/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:18:10 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 13:00:05 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
 
class	Dog : public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog(void);

		Dog & operator =(Dog const &rhs);

		void		makeSound(void) const;
		std::string	getIdea(int i) const;
		void  		setIdea(int i, std::string const & idea);
};

#endif
