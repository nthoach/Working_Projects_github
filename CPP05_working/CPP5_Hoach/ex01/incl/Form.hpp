/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/24 18:22:56 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class   Form
{
    private:
        const std::string _name;
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
        //Grade incre/decre
        void promote();
        void demote();
		
		//overload insertion
		friend std::ostream& operator<<(std::ostream& os, const Form& b);
        
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
		void beSigned(const Bureaucrat &n);
};

#endif