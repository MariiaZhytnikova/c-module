/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:52:48 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:49 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void ){
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "My test:" << std::endl;
	std::cout << "Operator >" << std::endl;
	std::cout << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << b << " > " << a << ": " << (b > a) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator <" << std::endl;
	std::cout << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << b << " < " << a << ": " << (b < a) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator >=" << std::endl;
	std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << a << " >= " << a << ": " << (a >= a) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator <=" << std::endl;
	std::cout << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << b << " <= " << b << ": " << (b <= b) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator ==" << std::endl;
	std::cout << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << a << " == " << a << ": " << (a == a) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator a != b" << std::endl;
	std::cout << a << " != " << b << ": " << (a != b) << std::endl;
	std::cout << a << " != " << a << ": " << (a != a) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator +" << std::endl;
	std::cout << a << " + " << b << ": " << (a + b) << std::endl;
	std::cout << a << " + " << a << ": " << (a + a) << std::endl;
	std::cout << b << " + " << b << ": " << (b + b) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator -" << std::endl;
	std::cout << a << " - " << b << ": " << (a - b) << std::endl;
	std::cout << a << " - " << a << ": " << (a - a) << std::endl;
	std::cout << b << " - " << b << ": " << (b - b) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator *" << std::endl;
	std::cout << a << " * " << b << ": " << (a * b) << std::endl;
	std::cout << a << " * " << a << ": " << (a * a) << std::endl;
	std::cout << b << " * " << b << ": " << (b * b) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator /" << std::endl;
	std::cout << a << " / " << b << ": " << (a / b) << std::endl;
	std::cout << a << " / " << a << ": " << (a / a) << std::endl;
	std::cout << b << " / " << b << ": " << (b / b) << std::endl;
	std::cout << std::endl;

	std::cout << "Operator ++x" << std::endl;
	std::cout << "++" << a << ": "<< ++a << std::endl;
	std::cout << "++" << a << ": "<< ++a << std::endl;
	std::cout << std::endl;

	std::cout << "Operator x++" << std::endl;
	std::cout << a << "++: " << a++ << " and a: " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Operator --x" << std::endl;
	std::cout << "--" << a << ": "<< --a << std::endl;
	std::cout << std::endl;

	std::cout << "Operator x--" << std::endl;
	std::cout << a << "--: " << a-- << " and a: "<< a << std::endl;
	std::cout << std::endl;

	std::cout << "MAX" << std::endl;
	std::cout << "max(" << a << ", " << b << "): " << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	std::cout << "MIN" << std::endl;
	std::cout << "min(" << a << ", " << b << "): " << Fixed::min( a, b ) << std::endl;
	std::cout << std::endl;

	return 0;
}