/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:56:17 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:36 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fraction = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		Fixed(const int inum);
		Fixed(const float fnum);

		// Getters
		int getRawBits(void) const;

		// Setters
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

};

	std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif