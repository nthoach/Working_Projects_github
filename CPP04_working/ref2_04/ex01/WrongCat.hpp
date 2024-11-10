/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:26:09 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 10:41:03 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		//WrongCat(std::string type);
		WrongCat(const WrongCat &copy);
		~WrongCat(void);

		WrongCat & operator =(WrongCat const &rhs);

		void		makeSound(void) const;
};


#endif
