/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 18:14:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/Intern.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/AForm.hpp"

// Canonical orthodox form

Intern::Intern() {}

Intern::~Intern(){}

// Exceptions
const char* Intern::FormNotFoundException::what() const throw()
{
    return "error: form not found";
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target) const
{
    //Array of form names
    std::string const names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
	// Array of form constructors
    AForm* (*constructors[])(std::string const& target) = {
        &ShrubberyCreationForm::create,
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create
    };

	// matching form name with constructor via idex number
    for (int i = 0; i < 3; ++i)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return constructors[i](target);
        }
    }
    throw Intern::FormNotFoundException();
	return NULL;

}
