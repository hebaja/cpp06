#pragma once

class Base;

class Func
{
	public:
		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
};
