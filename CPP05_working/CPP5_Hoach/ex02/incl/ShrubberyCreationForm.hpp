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
    public:
        //Orthodox Canonical ShrubberyCreationForm
        ShrubberyCreationForm(): AForm("ShurrubberyCreationForm", 145, 137) {};
        virtual ~ShrubberyCreationForm();

        //Getters
        std::string getName() const;
        bool getSigned() const;
        int  getGradeSign() const;
        int  getGradeExec() const;

        //Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        //
        void beSigned(Bureaucrat const& b);
};

//Overload operator
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b);

#endif