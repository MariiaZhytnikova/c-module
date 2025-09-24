#pragma once

#include <string>
#include <vector>
#include <utility>
#include <iostream>

class BitcoinExchange {
	private:
		std::vector<std::pair<std::string, double>> _data;
		std::vector<std::pair<std::string, double>> _input;
		BitcoinExchange();

	public:
		BitcoinExchange(std::istream& dataRates, std::istream& input);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void parseRates(std::istream& dataRates);
		void parseInput(std::istream& input);
		void Exchange();
		double SearchDate(const std::string& date) const;
		double searchClosest(const std::string& date) const;

		const std::vector<std::pair<std::string,double>>& getData() const;
		const std::vector<std::pair<std::string,double>>& getInput() const;
};

std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<std::string, double>>& pairs);