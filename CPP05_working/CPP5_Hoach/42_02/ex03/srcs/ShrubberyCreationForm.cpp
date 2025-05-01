/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:20:59 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/28 17:09:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include <fstream>

// Canonical orthodox form

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}
	

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
	

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// all getters
std::string ShrubberyCreationForm::getTarget() const  { return _target; }

//
void ShrubberyCreationForm::execute(Bureaucrat const& b) const
{
	this->checkExec(b);
	this->drawTrees();
	std::cout << _target << " has been shrubbed" << std::endl;
}

// Draw trees

void ShrubberyCreationForm::drawTrees() const
{
    std::ofstream ofs((_target + "_shrubbery").c_str());

    if (!ofs)
    {
        std::cerr << "Error: Could not open file " << _target + "_shrubbery" << std::endl;
        return;
    }
    // Draw a full picture
    ofs << "       ^            ^            ^" << std::endl;
    ofs << "      /|\\          /|\\          /|\\" << std::endl;
    ofs << "     /*|O\\        /*|O\\        /*|O\\" << std::endl;
    ofs << "    /*/|\\*\\      /*/|\\*\\      /*/|\\*\\" << std::endl;
    ofs << "   /X/O|*\\X\\    /X/O|*\\X\\    /X/O|*\\X\\" << std::endl;
    ofs << "      |||          |||          |||" << std::endl;
    ofs << "      |||          |||          |||" << std::endl;
    ofs << "      |||          |||          |||" << std::endl;
    ofs << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    ofs << " \" \" \" \" \" \" \" \" \" \" \" \" \" \" \" \" \" " << std::endl;
    ofs << "   ^   ^    ^     ^   ^     ^     ^" << std::endl;
    ofs.close();
}
