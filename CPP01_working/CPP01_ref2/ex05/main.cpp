/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:38:21 by imontero          #+#    #+#             */
/*   Updated: 2023/12/11 18:42:33 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//Chose between "DEBUG", "INFO", "WARNING", "ERROR"
int	main(void)
{
	Harl	inst;

	inst.complain("DEBUG");
	inst.complain("INFO");
	inst.complain("WARNING");
	inst.complain("ERROR");
	inst.complain("POTXOLO");
	return (0);
}