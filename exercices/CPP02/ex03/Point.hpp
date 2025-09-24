/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:53:06 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:19 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};


bool bsp(const Point& point, const Point& a, const Point& b, const Point& c);

#endif