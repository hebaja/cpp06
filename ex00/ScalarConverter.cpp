#include "ScalarConverter.hpp"
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

bool	is_print(char c)
{
	if (c >= ' ' && c <= '~')
		return (true);
	return (false);
}

bool	is_int_limit(double num)
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
	if (pseudo.compare("nan") == 0 
		|| pseudo.compare("inf") == 0
		|| pseudo.compare("+inf") == 0
		|| pseudo.compare("-inf") == 0)
	{
		tmp = pseudo;
		tmp += 'f';
		std::cout << "float: " << tmp << std::endl;
	}
	else
		std::cout << "float: " << pseudo << std::endl;
	if (pseudo.length() == 5)
		pseudo.erase(4);
	else if (pseudo.compare("nanf") == 0 || pseudo.compare("inff") == 0)
		pseudo.erase(3);
	std::cout << "double: " << pseudo << std::endl;
}

bool isValidNumber(const std::string &s)
{
	if (s.empty())
        return false;

    std::string tmp = s;
    if (tmp[tmp.size() - 1] == 'f' || tmp[tmp.size() - 1] == 'F')
    {
        if (tmp.size() == 1)
            return false;
        tmp = tmp.substr(0, tmp.size() - 1);
    }
    char *end;
    std::strtod(tmp.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(std::string literal)
{
	int		int_val;
	float	float_val;
	double	double_val;

	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0 
		|| literal.compare("inf") == 0 || literal.compare("+inf") == 0
		|| literal.compare("-inf") == 0 || literal.compare("inff") == 0
		|| literal.compare("+inff") == 0 || literal.compare("-inff") == 0)  
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
	else if (isValidNumber(literal))
	{
		std::stringstream ss(literal);
		ss >> int_val;
		std::stringstream sf(literal);
		sf >> float_val;
		std::stringstream sd(literal);
		sd >> double_val;
	}
	else
	{
		std::cout << "malformed input" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (int_val >= 0 && int_val <= 127 && is_print(int_val))
		std::cout << '\'' << static_cast<char>(int_val) << '\'';
	else
		std::cout << "Non displayable";
	std::cout << std::endl;

	std::cout << "int: ";
	if (is_int_limit(double_val))
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
