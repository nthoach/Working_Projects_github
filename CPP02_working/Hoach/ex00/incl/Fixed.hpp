/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:23:11 by honguyen          #+#    #+#             */
/*   Updated: 2024/11/11 17:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _nfixed = 8;

	public:
		// Constructor
		Fixed(int _value = 0);
		// Copy constructor
		Fixed(const Fixed& other);
		// Copy assignment
		Fixed& operator=(const Fixed &other);
		// Deconstructor
		~Fixed( );

		int getRawBits (void) const;
		void setRawBits (int const raw);
};

#endif