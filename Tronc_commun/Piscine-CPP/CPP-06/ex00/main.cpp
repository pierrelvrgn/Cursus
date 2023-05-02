#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

bool	checkInt(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	double checkInt = atof(str.c_str());
	if (checkInt < std::numeric_limits<int>::min() || checkInt > std::numeric_limits<int>::max())
		return false;
	return (true);
}

bool	checkDouble(std::string str)
{
	if (str == "nan" || str == "NaN" || str == "+inf" || str == "-inf")
		return (true);
	int index = 0;
	if (str[0] == '+' || str[0] == '-')
		index ++;
	while (str[index] && std::isdigit(str[index]))
		index ++;
	if (str[index] != '.' || (str[index] == '.' && !str[index + 1]))
		return (false);
	index ++;
	while (str[index] && std::isdigit(str[index]))
		index ++;
	if (str[index])
		return (false);
	double checkInt = atof(str.c_str());
	if (checkInt < std::numeric_limits<double>::min() || checkInt > std::numeric_limits<double>::max())
		return false;
	return (true);
}

bool checkChar(std::string str)
{
	if (str.size() == 1)
		return (true);
	if (str.size() == 3)
	{
		if (str[0] != '\'' || str[2] != '\'')
			return false;
		if (str[1] < std::numeric_limits<char>::min() || str[1]  > std::numeric_limits<char>::max())
			return false;
	}
	return (false);
}

bool checkFloat(std::string str)
{
	int index = 0;
	if (str == "nan" || str == "NaN" || str == "nanf" || str == "NaNf" || str == "+inff" || str == "-inff")
		return (true);
	if (str[0] == '+' || str[0] == '-')
		index++;
	while (str[index] && std::isdigit(str[index]))
		index++;
	if (str[index] != '.')
		return (false);
	index++;
	if (!std::isdigit(str[index]))
		return (false);
	while (str[index] && std::isdigit(str[index]))
		index++;
	if (str[index] != 'f')
		return (false);
	if (!str[index + 1])
		return (true);
	return (false);
	double checkFloat = atof(str.c_str());
	if (checkFloat < std::numeric_limits<float>::min() || checkFloat > std::numeric_limits<float>::max())
		return false;
	return (true);
}

int	checkType(std::string str)
{
	if (checkInt(str))
		return (1);
	else if (checkChar(str))
		return (2);
	else if (checkFloat(str))
		return (3);
	else if (checkDouble(str))
		return (4);
	return (0);
}

void	printInt(int _i, std::string str)
{
	int index = 0;
	int neg = 0;
	if (str[index] == '-')
	{
		index ++;
		neg = 1;
	}
	if (str == "nan" || str == "NaN" || str == "nanf" || str == "NaNf")
	{
		std::cout << "Int : impossible" << std::endl;
		return ;
	}
	else if (str == "+inff" || str == "-inff")
	{
		std::cout << "Int : overflow" << std::endl;
		return ;
	}
	while (str[index] && std::isdigit(str[index]))
		index ++;
	if (neg == 1 && index > 11)
		std::cout << "Int : overflow" << std::endl;
	else if (neg == 0 && index > 10)
		std::cout << "Int : overflow" << std::endl;
	else if (neg == 1 && index == 11 && str[10] == 57)
		std::cout << "Int : overflow" << std::endl;
	else if (neg == 0 && index == 10 && str[10] == 56)
		std::cout << "Int : overflow" << std::endl;
	else
		std::cout << "Int : " << _i << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR : Invalid input !" << std::endl;
		return 0;
	}
	std::string str = argv[1];
	if (str.size() == 0)
	{
		std::cout << "ERROR : Invalid input !" << std::endl;
		return 0;
	}
	int type = checkType(str);
	int _int;
	char _char;
	float _float;
	double _double;
	switch (type)
	{
		case 3:
			_float = static_cast<float>(strtod(argv[1], NULL));
			_int = static_cast<int>(_float);
			_char = static_cast<char>(_float);
			_double = static_cast<double>(_float);
			break;
		case 4:
			_double = static_cast<double>(strtod(argv[1], NULL));
			_int = static_cast<int>(_double);
			_char = static_cast<char>(_double);
			_float = static_cast<float>(_double);
			break;
		case 2:
			_char = static_cast<char>(argv[1][0]);
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
			break;
		case 1:
			_int = static_cast<int>(atoi(argv[1]));
			_char = static_cast<char>(_int);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
			break;
		default:
			std::cout << "No type detected" << std::endl;
			return (0);
	}
	if(std::isprint(_char) && _int < 256 && _int > 1)
		std::cout << "Char : '" << _char << "'" << std::endl;
	else if (str.size() > 1)
		std::cout << "Char : impossible" << std::endl;
	else
		std::cout << "Char : Non displayable" << std::endl;
	printInt(_int, argv[1]);

	if (!fmod(_float, 1))
		std::cout << "Float : " << _float << ".0f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(5) << "Float : " << _float << "f" << std::endl;

	if (!fmod(_double, 1))
		std::cout << "Double : " << _double << ".0" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(5) << "Double : " << _double << std::endl;
	return 1;
}
