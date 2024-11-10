/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:05:47 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 17:15:47 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
	private:
		Brain	*_brain;
	
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat(void);

		Cat & operator =(Cat const &rhs);

		void		makeSound(void) const;
		std::string	getIdea(int i) const;
		void  		setIdea(int i, std::string const & idea);
};





#endif
