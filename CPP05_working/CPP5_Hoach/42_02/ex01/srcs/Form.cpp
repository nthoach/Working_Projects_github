/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 18:21:59 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"

// Canonical orthodox form

Form::Form(): _name("DefaultForm"), _signed(false), _grade_sign(150), _grade_exec(150) {}

Form::Form(std::string name, int grade_sign, int grade_exec): _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    _signed = false;
    if (_grade_sign < 1 || _grade_exec < 1)
        throw Form::GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), \
    _grade_exec(other._grade_exec) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed = other._signed;
        std::cout << other.getName() << " three constant parameters cannot be assigned to " << *this <<" due to constant name." <<std::endl;
    }
    return *this;
}

Form::~Form() {}

// all getters
std::string Form::getName() const  { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeSign() const { return _grade_sign; }

int Form::getGradeExec() const { return _grade_exec; }


// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > _grade_sign)
        throw Form::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << b.getName() << " signed " << _name << std::endl;
    }

}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os << b.getName() << ", signed = " << b.getSigned() << ", grade to sign = " << b.getGradeSign() \
       << ", grade to execute = " << b.getGradeExec() << ".";
    return os;
}
