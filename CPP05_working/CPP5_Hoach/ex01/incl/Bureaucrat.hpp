/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 05:17:37 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
        Bureaucrat(std::string type, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
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
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		//
		void signForm(Form &f) const;

};

//Overload operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif