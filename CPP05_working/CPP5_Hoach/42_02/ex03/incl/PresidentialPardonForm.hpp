/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:54:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTPARDON_HPP
# define PRESIDENTPARDON_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class   PresidentialPardonForm: public AForm
{
    private:
        std::string _target;

    public:
        //Orthodox Canonical PresidentialPardonForm
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target = "Default");
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();

        //Getters
        std::string getTarget() const;

        virtual void execute(Bureaucrat const& b) const;
};


#endif