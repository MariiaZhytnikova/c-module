/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:52:41 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:43 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath> 

Fixed::Fixed() : _value(0) {
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
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

Fixed::Fixed(const Fixed& other) {
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

bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long long temp = (long long)_value * other._value;
	result._value = (int)(temp >> _fraction);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	long long temp = ((long long)_value << _fraction) / other._value;
	result._value = (int)temp;
	return result;
}

Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
