/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2025/04/25 15:54:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class   RobotomyRequestForm: public AForm
{
    private:
        std::string _target;

    public:
        //Orthodox Canonical RobotomyRequestForm
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target = "Default");
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();

        //Getters
        std::string getTarget() const;

        virtual void execute(Bureaucrat const& b) const;
};


#endif