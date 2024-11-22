/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/22 12:03:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap
{
    public:
        ClapTrap(std::string name = "Unnamed", int hit = 10, int energy = 10, int damage = 0);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        virtual ~ClapTrap();

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        virtual void showStatus(void);

        //methods to access
        virtual std::string getName() const;
        virtual int         getDamage() const;
        virtual void        setDamage(int damage);

    protected:
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
        bool        actable(void);
};

#endif