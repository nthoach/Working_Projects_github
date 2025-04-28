/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:54:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class   ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;

    public:
        //Orthodox Canonical ShrubberyCreationForm
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target = "Default");
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        //Getters
        std::string getTarget() const;

        virtual void execute(Bureaucrat const& b) const;

		//
		void drawTrees() const;

		static AForm* create(std::string const& target);
		

};


#endif