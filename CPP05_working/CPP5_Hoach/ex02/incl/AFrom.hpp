/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:54:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;

    public:
        //Orthodox Canonical AForm
        AForm();
        AForm(std::string name = "DefaultForm", int grade_sign = 150, int grade_exec = 150);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

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
        virtual void beSigned(Bureaucrat const& b) const = 0;
};

//Overload operator
std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif