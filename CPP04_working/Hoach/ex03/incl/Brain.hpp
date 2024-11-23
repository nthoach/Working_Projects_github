/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/23 14:15:32 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# define SIZE 100

class   Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();

        const std::string   getIdea(int i) const;
        std::string         getIdea(int i);
        void                setIdea(int i, std::string const & idea);

    protected:
        std::string _ideas[SIZE];

};

#endif