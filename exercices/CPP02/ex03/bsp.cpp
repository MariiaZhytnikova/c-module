/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:52:51 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:52:52 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed area(const Point& p1, const Point& p2, const Point& p3) {
	Fixed area = (p1.getX() * (p2.getY() - p3.getY())
				+ p2.getX() * (p3.getY() - p1.getY())
				+ p3.getX() * (p1.getY() - p2.getY())) / 2;
	return area < Fixed(0) ? area * Fixed(-1) : area;
}

bool bsp(const Point& point, const Point& a, const Point& b, const Point& c) {
	Fixed p1 = area(point, a, b);
	Fixed p2 = area(point, b, c);
	Fixed p3 = area(point, c, a);
	Fixed t = area(a, b, c);

	if (p1 == Fixed(0) || p2 == Fixed(0) || p3 == Fixed(0))
		return false;

	return (t == p1 + p2 + p3);
}
