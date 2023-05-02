#pragma once
#include <string>
#include <stdint.h>

typedef struct
{
	std::string	test1;
	int			test2;
} Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
