/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 18:14:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"

// Canonical orthodox form

AForm::AForm(): _name("Default"), _signed(false), _grade_sign(150), _grade_exec(150) {}

AForm::AForm(std::string name, int grade_sign, int grade_exec): _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
    _signed = false;
    if (_grade_sign < 1 || _grade_exec < 1)
        throw AForm::GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(false), _grade_sign(other._grade_sign), \
    _grade_exec(other._grade_exec) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed = false;
        std::cout << other.getName() << "three constant parameters cannot be assigned to " << *this <<" due to constant name." <<std::endl;
    }
    return *this;
}

AForm::~AForm() { std::cout << "Destructor called for form: " << _name << std::endl; }

// all getters
std::string AForm::getName() const  { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeSign() const { return _grade_sign; }

int AForm::getGradeExec() const { return _grade_exec; }


// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

const char* AForm::notSigned::what() const throw()
{
    return "Form is not signed";
}

void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > _grade_sign)
        throw AForm::GradeTooLowException();
    else
    {
        _signed = true;
        std::cout << b.getName() << " signed " << _name << std::endl;
    }

}
void AForm::checkExec(Bureaucrat const& b) const
{
	if (!_signed)
		throw AForm::notSigned();
	else if (_grade_exec < b.getGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << b.getName() << " passed check for execution " << _name << std::endl;
		return;
	}
}

//
std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os << b.getName() << ", signed = " << b.getSigned() << ", grade to sign = " << b.getGradeSign() \
       << ", grade to execute = " << b.getGradeExec() << ".";
    return os;
}
