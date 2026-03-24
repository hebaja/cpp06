#include "Func.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*Func::generate(void)
{
	int	rand_num;

	std::srand(std::time(0));
	rand_num = std::rand() % 3;
	switch (rand_num) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	Func::identify(Base* p)
{
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type";
}

void	Func::identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception&) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::bad_cast&) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::bad_cast e) {
				std::cout << e.what() << " : Unknown type";
			}
		}
	}
}
