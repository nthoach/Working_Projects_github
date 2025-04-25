<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 16:23:22 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
=======
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 05:17:13 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class   Form
{
    private:
        const std::string _name;
<<<<<<< HEAD
        bool _signed;
        const int _grade_sign;
        const int _grade_exec;

    public:
        //Orthodox Canonical Form
        Form();
        Form(std::string name = "DefaultForm", int grade_sign = 150, int grade_exec = 150);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

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
=======
		bool _signed;
		const int _grade2sign;
        const int _grade2exec;

    public:
        //Orthodox Canonical Form
		Form();
        Form(std::string name, int grade2sign, int grade2exec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        virtual ~Form();
        //Getters
        std::string getName() const;
        bool getSigned() const;
		int  getGrade2Sign() const;
		int getGrade2Exec() const;
    		
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
		void beSigned(const Bureaucrat &b);
};

//overload insertion
std::ostream& operator<<(std::ostream& os, const Form& b);
        
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

#endif