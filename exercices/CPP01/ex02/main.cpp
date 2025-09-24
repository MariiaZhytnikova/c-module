/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:11 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:49:29 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str;

	str = "HI THIS IS BRAIN";

	std::string* strPTR = &str;
	std::string& strREF = str;

	std::cout << "Printing memory addresses" << std::endl;

	std::cout << "String variable: " << &str << std::endl;
	std::cout << "StringPTR      : " << strPTR << std::endl;
	std::cout << "StringREF      : " << &strREF << std::endl;

	std::cout << "\nPrinting values" << std::endl;

	std::cout << "String variable: " << str << std::endl;
	std::cout << "StringPTR      : " << *strPTR << std::endl;
	std::cout << "StringREF      : " << strREF << std::endl;

	return 0;
}