/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:52:16 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:02 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {

	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 4);

	Point p1(2, 1);
	Point p2(5, 5);

	std::cout << "Point (" << p1.getX() << ","<< p1.getY() << ") \n";
	if (bsp(p1, a, b, c)) {
		std::cout << "is inside the triangle\n";
	} else {
		std::cout << "is outside the triangle\n";
	}

	std::cout << "Point (" << p2.getX() << ","<< p2.getY() << ") \n";
	if (bsp(p2, a, b, c)) {
		std::cout << "is inside the triangle\n";
	} else {
		std::cout << "is outside the triangle\n";
	}
	return 0;
}