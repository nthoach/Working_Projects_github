/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 16:29:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class   Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:

        //Orthodox Canonical AForm
        Bureaucrat();
        Bureaucrat(std::string type = "Default", int grade = 150);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //Getters
        std::string getName() const;
        int getGrade() const;

        //Grade incre/decre
        void promote();
        void demote();
        
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

        void signForm(AForm &f);
        void executeForm(AForm const &f);

};

//Overload operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif