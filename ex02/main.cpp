#include "Base.hpp"
#include "Func.hpp"
#include <iostream>

int	main()
{
	Base *b = Func::generate();
	std::cout << b << std::endl;
	Func::identify(b);
	Func::identify(*b);

	return (0);
}
