/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:38:52 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 15:38:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name; // Private name specific to DiamondTrap

    public:
        // Constructor
        DiamondTrap(const std::string& name = "_clap_name");
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        // Destructor
        ~DiamondTrap();

        // Special capacity
        void whoAmI();

        // Overriding attack from ScavTrap
        void attack(const std::string& target);
        void showStatus(void);
};

#endif
