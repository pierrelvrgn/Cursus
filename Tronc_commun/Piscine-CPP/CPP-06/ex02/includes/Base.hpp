#pragma once
#include <iostream>
#include <cstdlib>

class Base
{
	public:
		Base(){}
		virtual ~Base(){}
};

Base* generate();
void identify(Base* p);
void identify(Base& p);
