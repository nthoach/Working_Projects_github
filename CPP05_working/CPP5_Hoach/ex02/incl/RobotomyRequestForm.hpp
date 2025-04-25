/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:54:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;

    public:
        //Orthodox Canonical Form
        Form();
        Form(std::string name = "DefaultForm", int grade_sign = 150, int grade_exec = 150);
        Form(const Form& other);
        Form& operator=(const Form& other);
        virtual ~Form();

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
std::ostream& operator<<(std::ostream& os, const Form& b);

#endif