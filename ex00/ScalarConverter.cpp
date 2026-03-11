#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	check_is_int(std::string literal)
{
	return (!(literal.length() > 1 && literal.find_first_not_of("0123456789") != std::string::npos));
}

bool	check_is_double(std::string literal)
{
	if (literal[0] == '.')
		return (false);
	if (std::count(literal.begin(), literal.end(), '.') != 1)
		return (false);
	if (literal.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	return (true);
}

bool	check_is_float(std::string literal)
{
	if (std::count(literal.begin(), literal.end(), '.') != 1)
		return (false);
	return (literal[literal.length() - 1] == 'f' && is_digit(literal[literal.length() - 2]));
}

bool	is_print(char c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}

bool	is_int_lmt(double num)
{
	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

void	print_pseudo(std::string pseudo)
{
	std::string	tmp;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (pseudo.length() == 4)
	{
		tmp = pseudo;
		tmp += 'f';
		std::cout << "float: " << tmp << std::endl;
	}
	else
		std::cout << "float: " << pseudo << std::endl;
	if (pseudo.length() == 5)
		pseudo.erase(4);
	std::cout << "double: " << pseudo << std::endl;
}

double	parse_input(std::string literal)
{
	double	valid = false;

	if (check_is_int(literal))
		valid = true;
	else if (check_is_float(literal))
	 	valid = true;
	else if (check_is_double(literal))
		valid = true;
	return (valid);
}

void ScalarConverter::convert(std::string literal)
{
	int		int_val;
	float	float_val;
	double	double_val;

	if (!parse_input(literal))
	{
		std::cout << "malformed input" << std::endl;
		return ;
	}

	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0 
		|| literal.compare("-inf") == 0 || literal.compare("-inff") == 0
		|| literal.compare("+inf") == 0 || literal.compare("+inff") == 0)
	{
		print_pseudo(literal);
		return ;
	}
	else if (literal.length() == 1 && is_print(literal[0]))
	{
		if (is_digit(literal[0]))
		{
			std::stringstream ss(literal);
			ss >> int_val;
		}
		else
			int_val = literal[0];
		float_val = static_cast<float>(int_val);
		double_val = static_cast<double>(int_val);
	}
	else
	{
		std::stringstream ss(literal);
		ss >> int_val;
		std::stringstream sf(literal);
		sf >> float_val;
		std::stringstream sd(literal);
		sd >> double_val;
	}

	std::cout << "char: ";
	if (is_print(int_val))
		std::cout << '\'' << (char)int_val << '\'';
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: ";
	if (is_int_lmt(double_val))
		std::cout << int_val; 
	else
		std::cout << "impossible";
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(1);

	std::cout << "float: "; 
	double freal = std::strtod(literal.c_str(), NULL);
	if (std::isinf(freal))
	    std::cout << "impossible";
	else
		std::cout << float_val << 'f';
	std::cout << std::endl;

	std::cout << "double: ";
	double real = std::strtod(literal.c_str(), NULL);
	if (std::isinf(real))
	    std::cout << "impossible";
	else
		std::cout << double_val;
	std::cout << std::endl;
}
