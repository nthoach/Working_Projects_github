/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:00:43 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/20 20:01:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   ClapTrap
{
    public:
        ClapTrap(std::string _name = "Unnamed");
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        bool        showStatus(void);

        //methods to access
        std::string getName( );
        void        setDamage(const int damage);
    
    private:
        std::string _name;
        int         _hit;
        int         _energy;
        int         _damage;
        bool        actable(void);
};
