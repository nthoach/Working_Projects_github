/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class   Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:

        //Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(std::string type, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();

        //Getters
        std::string getName() const;
        int getGrade() const;

        //Grade incre/decre
        void increGrade();
        void decreGrade();
        
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

        void signForm(Form &f);

};

//Overload operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif