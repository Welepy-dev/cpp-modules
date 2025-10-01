#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <iostream>
#include <chrono>

Base::Base()
{
	std::cout << "Base's default constructor called" << std::endl;
} 
 
Base::~Base()
{ 
	std::cout << "Base's default destructor called" << std::endl;
}

Base	*Base::generate(void)
{
	std::time_t now = std::time(nullptr);
	std::tm* local = std::localtime(&now);

	int second = local->tm_sec;  // 0–60 (leap seconds possible)
	Base *base;
	
	if (second / 3 == 0)
		base = new A;
	else if (second / 3 == 1)
		base = new B;
	else
		base = new C;
	return base;
}

void	Base::identify(Base *p)
{
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "Type A identified" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "Type B identified" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "Type C identified" << std::endl;
	else
		std::cout << "Unknow type" << std::endl;
}

void	Base::identify(Base &p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Type A identified" << std::endl;
		return;
	} catch (std::bad_cast&) {
		std::cout << "Bad cast" << std::endl;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (std::bad_cast&) {
		std::cout << "Bad cast" << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (std::bad_cast&) {
		std::cout << "Bad cast" << std::endl;
	}

}

/*
Base* b = new Derived();

if (Derived* d = dynamic_cast<Derived*>(b)) {
	std::cout << "It’s a Derived\n";
} else {
	std::cout << "Not a Derived\n";
}
*/

