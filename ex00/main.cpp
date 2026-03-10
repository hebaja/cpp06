#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string cpp_str(argv[1]);
		ScalarConverter::convert(cpp_str);
	}
	return (0);
}

/*
./convert a
	char: 'a'
	int: 97
	float: 97.0f
	double: 97.0
./convert 0
	char: Non displayable
	int: 0
	float: 0.0f
	double: 0.0
./convert nan
	char: impossible
	int: impossible
	float: nanf
	double: nan
./convert 42.0f
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
./convert 42.0
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
./convert c
	char: c
	int: 99
	float: 99.0f
	double: 99.0
./convert -inf
	char: impossible
	int: impossible
	float: -inff
	double: -inf
./convert -42
	char: Non displayable
	int: -42
	float: -42.0f
	double: -42.0
./convert 9999999999999999999999999999999999999
	char: Non displayable
	int: impossible
	float: -1.0f
	double: -1.0
./convert -9999999999999999999999999999999999999
	char: Non displayable
	int: impossible
	float: 0.0f
	double: 0.0

*/

