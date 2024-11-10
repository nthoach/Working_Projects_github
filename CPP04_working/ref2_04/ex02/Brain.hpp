/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:01:48 by imontero          #+#    #+#             */
/*   Updated: 2023/12/20 13:07:03 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string		_ideas[100];
		
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		Brain & operator =(Brain const &rhs);

		std::string	getIdea(int i) const;
		void  		setIdea(int i, std::string const & idea);

};



#endif
