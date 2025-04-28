/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 18:24:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

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
	{
		_grade = other._grade;
		std::cout << other.getName() << " cannot be assigned to " << _name <<" due to constant name." <<std::endl;
	}

    return *this;
}

Bureaucrat::~Bureaucrat() {}

//getters
std::string Bureaucrat::getName() const { return _name; }

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
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}


void Bureaucrat::signForm(AForm & f)
{
   try
   {
        f.beSigned(*this);
   }
   catch (std::exception &e)
   {
        std::cout << _name << " couldn't sign " << f.getName() << " because " << \
        e.what() << std::endl;
   }
}

void Bureaucrat::executeForm(AForm const &f)
{
	try
	{
		f.execute(*this);  
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << f.getName() << " because " << \
		e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

