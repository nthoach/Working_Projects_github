<<<<<<< HEAD
/* ************************************************************************** */
=======
/******************************************************************************/
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 16:23:33 by honguyen         ###   ########.fr       */
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
=======
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 05:32:59 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../incl/Form.hpp"

Form::Form(): _name("UNINITIALIZED"), _signed(false), _grade2sign(1), _grade2exec(1)  {}

Form::Form(std::string name, int grade2sign, int grade2exec): 
_name(name), _signed(false), _grade2sign(grade2sign), _grade2exec(grade2exec)
{
    if (grade2sign < 1  || grade2exec < 1)
        throw Form::GradeTooHighException();
    else if (grade2sign > 150 || grade2exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), \
	_grade2sign(other._grade2sign), _grade2exec(other._grade2exec) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		return *this;
	}
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
    return *this;
}

Form::~Form() {}

<<<<<<< HEAD
// all getters
std::string Form::getName() const  { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeSign() const { return _grade_sign; }

int Form::getGradeExec() const { return _grade_exec; }


// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
=======
std::string Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGrade2Sign() const { return _grade2sign; }

int Form::getGrade2Exec() const { return _grade2exec; }

const char* Form::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException: grade to sign/exec is too high";
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
}

const char* Form::GradeTooLowException::what() const throw()
{
<<<<<<< HEAD
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

=======
    return "GradeTooLowException: grade to sign/exec is too low";
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
<<<<<<< HEAD
    os << b.getName() << ", signed = " << b.getSigned() << ", grade to sign = " << b.getGradeSign() \
       << ", grade to execute = " << b.getGradeExec() << ".";
    return os;
}
=======
    os << b.getName() << ", signed " << b.getSigned() << ", grade2sign " << b.getGrade2Sign() \
	<< ", grade2exec " << b.getGrade2Exec() << ".";
    return os;
}


void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGrade2Sign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
