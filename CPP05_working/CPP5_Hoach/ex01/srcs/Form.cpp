/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/24 18:27:36 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/Form.hpp"

Form::Form(): _name("UNINITIALIZED"), _signed(false), _grade2sign(1), _grade2exec(1)  {}

Form::Form(std::string name, int grade2sign, int grade2exec): 
_name(name), _signed(false), _grade2sign(grade2sign), _grade2exec(grade2exec)
{
    if (grade2sign < 1  || grade2exec < 1)
        throw Form::GradeTooHighException();
    else if (grade > 150 || grade2exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) { *this = other}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
		_name = other._name;
		_signed = other._signed;
		_grade2sign = other._grade2sign;
		_grade2exec = other._grade2exec;
	}
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGrade2Sign() const { return _grade2sign; }

int Form::getGrade2Exec() const { return _grade2exec; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: grade to sign/exec is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: grade to sign/exec is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os << b.getName() << ", signed " << b.getSigned() << ", grade2sign " << b.getGrade2Sign() \
	<< ", grade2exec " << b.getGrade2Exec() << ".";
    return os;
}


//
        //Orthodox Canonical Form
	
        Form(std::string _name, int _grade2sign, int _grade2exec);
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
		void beSigned(const Form &n);