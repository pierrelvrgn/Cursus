#include <iostream>

int	main(int argc, char **argv)
{
	std::string tmp;
	int	check = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int index = 1; index < argc; index++)
	{
		tmp = argv[index];
		for (std::string::iterator it = tmp.begin(); it < tmp.end(); it++)
		{
			*it = toupper(*it);
			check++;
		}
		std::cout << tmp;
	}
	if (check > 0)
		std::cout << std::endl;
	return (0);
}
