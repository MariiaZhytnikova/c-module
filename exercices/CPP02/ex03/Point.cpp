/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:53:03 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:05 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) {
	*this = other;
}

Point& Point::operator=(const Point& other) {
	(void)other;
	std::cerr << "Not implemented because we use const members\n";
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}