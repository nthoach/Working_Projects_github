<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 05:17:37 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

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

<<<<<<< HEAD
    public:

        //Orthodox Canonical Form
        Bureaucrat();
=======
    
    public:
        //Orthodox Canonical Form
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
        Bureaucrat(std::string type, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
<<<<<<< HEAD

        //Getters
        std::string getName() const;
        int getGrade() const;

        //Grade incre/decre
        void increGrade();
        void decreGrade();
        
=======
        //Getters
        std::string getName() const;
        int getGrade() const;
        //Grade incre/decre
        void promote();
        void demote();
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
        //Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
<<<<<<< HEAD
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        void signForm(Form &f);
=======
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		//
		void signForm(Form &f) const;
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

};

//Overload operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif