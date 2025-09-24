/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:56:14 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:32 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> 

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int inum) {
	std::cout << "Int constructor called" << std::endl;
	_value = inum << _fraction;
}

Fixed::Fixed(const float fnum) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(fnum * (1 << _fraction));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed:: toFloat(void) const {
	return (float)_value / (1 << _fraction);
}

int Fixed:: toInt(void) const {
	return _value >> _fraction;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
