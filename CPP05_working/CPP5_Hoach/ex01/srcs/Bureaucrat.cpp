/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 04:52:57 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string type, int grade) : _name(type), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
 { return _name; }

int Bureaucrat::getGrade() const 
{ return _grade; }

void Bureaucrat::promote() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::demote() {
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
//
void Bureaucrat::signForm(Form &f) const
{
	f.beSigned(*this);
	if (f.getSigned())
		std::cout << _name << " signed " << f.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << f.getName() << " because grade is too low" << std::endl;
}