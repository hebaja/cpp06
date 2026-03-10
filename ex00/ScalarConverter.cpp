#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

bool	check_is_nan(std::string literal)
{
	if (literal.find_first_not_of("0123456789") != std::string::npos)
		return (true);
	return (false);
}

bool	is_print(char c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_int_lmt(double num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (true);
	return (false);
}

bool	is_double_lmt(double num)
{
	const double	min_val = std::numeric_limits<double>::min();
	const double	max_val = std::numeric_limits<double>::max();


	if (num >= min_val && num <= max_val)
		return (true);
	return (false);
}

void	deal_nan(int is_minus_inf)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	is_minus_inf ? std::cout << "-inff" : std::cout << "nanf";
	std::cout << std::endl;
	std::cout << "double: ";
	is_minus_inf ? std::cout << "-inf" : std::cout << "nan";
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	int		int_val;
	float	float_val;
	double	double_val;

	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
	{
		deal_nan(0);
		return ;
	}
	else if (literal.compare("-inf") == 0 || literal.compare("-inff") == 0)
	{
		deal_nan(1);
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
	// float_val = static_cast<float>(int_val);
	// double_val = static_cast<double>(int_val);



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
	std::cout << float_val << 'f';
	std::cout << std::endl;

	std::cout << "double: ";
	std::cout << double_val;
	std::cout << "impossible";
	std::cout << std::endl;
	
	double real = std::strtod(literal.c_str(), NULL);
	if (std::isinf(real))
	    std::cout << "Overflow\n";
	std::cout << std::endl;
}
