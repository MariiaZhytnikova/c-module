#include <iostream>
#include <cctype>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	int		i = 1;
	size_t	j = 0;

	while (i < argc) {
		std::string str = argv[i];
		j = 0;
		while (j < str.length()) {
			std::cout << static_cast<char>(std::toupper(str[j]));
			j++;
		}
		if (i < argc - 1)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return 0;
}
