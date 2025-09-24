#include "BitcoinExchange.hpp"

static std::string trim(std::string s) {
	size_t i = 0;
	while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i]))) ++i;
	size_t j = s.size();
	while (j > i && std::isspace(static_cast<unsigned char>(s[j-1]))) --j;
	return s.substr(i, j - i);
}

static bool checkDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int		year	= std::stoi(date.substr(0,4));
	int		month	= std::stoi(date.substr(5,2));
	int		day		= std::stoi(date.substr(8,2));
	int		daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool	isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

	if (isLeap) daysInMonth[1] = 29;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

BitcoinExchange::BitcoinExchange(std::istream& dataRates, std::istream& input) {
	parseRates(dataRates);
	parseInput(input);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _data(other._data), _input(other._input) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
		_input = other._input;
	}

	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

const std::vector<std::pair<std::string,double>>&
	BitcoinExchange::getData() const {
	return _data;
}

const std::vector<std::pair<std::string,double>>&
	BitcoinExchange::getInput() const {
	return _input;
}



void BitcoinExchange::parseRates(std::istream& dataRates) {
	std::string		line;
	while (std::getline(dataRates, line)) {
		if (line.empty() || line == "date,exchange_rate")
			continue;

		size_t	pos = line.find(',');

		if (pos == std::string::npos) continue;

		std::string dateStr = trim(line.substr(0, pos));
		std::string valueStr = trim(line.substr(pos + 1));

		double value;
		try {
			size_t pos = 0;
			value = std::stod(valueStr, &pos);
			if (pos != valueStr.size())
				continue;
		}
		catch (const std::exception&) { continue; }
		if (value < 0 || !checkDate(dateStr))
			continue;
		_data.emplace_back(dateStr, value);
	}
}

void BitcoinExchange::parseInput(std::istream& input) {
	std::string		line;
	while (std::getline(input, line)) {
		if (line.empty() || line == "date | value")
			continue;

		size_t	pos = line.find('|');

		if (pos == std::string::npos) {
			_input.emplace_back(line, -1);
			continue;
		}

		std::string dateStr = trim(line.substr(0, pos));
		std::string valueStr = trim(line.substr(pos + 1));

		double value;
		try {
			size_t pos = 0;
			value = std::stod(valueStr, &pos);
			if (pos != valueStr.size()) {
				_input.emplace_back(line, -1);
				continue;
			}
		}
		catch (const std::exception&) {
			_input.emplace_back(line, -1);
			continue;
		}
		if (!checkDate(dateStr)) {
			_input.emplace_back(dateStr, -1);
			continue;
		}
		if (value > 1000)
		{
			_input.emplace_back(dateStr, -2);
			continue;
		}
		else if (value < 0) {
			_input.emplace_back(dateStr, -3);
			continue;
		}
		_input.emplace_back(dateStr, value);
	}
}

double BitcoinExchange::searchClosest(const std::string& date) const {
	int			year	= std::stoi(date.substr(0,4));
	int			month	= std::stoi(date.substr(5,2));
	int			day		= std::stoi(date.substr(8,2));
	double		rate = 0;

	for (const auto& p : _data) {
		int		yearData	= std::stoi(p.first.substr(0,4));
		int		monthData	= std::stoi(p.first.substr(5,2));
		int		dayData= std::stoi(p.first.substr(8,2));
		if (dayData <= day && monthData <= month && yearData <= year)
			rate = p.second;
	}
	return rate;
}

double BitcoinExchange::SearchDate(const std::string& date) const {
	for (const auto& p : _data) {
		if (p.first == date)
			return p.second;
	}
	return searchClosest(date);
}

void BitcoinExchange::Exchange() {
	for (const auto& p : _input) {
		if (p.second == -1)
			std::cout << "Error: bad input => " << p.first << std::endl;
		else if (p.second == -2)
			std::cout << "Error: too large a number." << std::endl;
		else if (p.second == -3)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << p.first << " => " << p.second << " = "
			<< p.second * SearchDate(p.first) << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<std::string, double>>& pairs) {
	for (const auto& p : pairs) {
		os << p.first << " -> " << p.second << std::endl;
	}
		return os;
};