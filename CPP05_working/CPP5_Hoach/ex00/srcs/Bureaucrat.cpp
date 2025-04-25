/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 14:40:02 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

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
        std::cout << other.getName() << " cannot be assigned to " << *this <<" due to constant name." <<std::endl;
    }

    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const  { return _name; }

int Bureaucrat::getGrade() const  { return _grade; }

void Bureaucrat::Promote()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::Demote()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high (< 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low (> 150)";
}

// independent function to overload the << operator -right side function

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
