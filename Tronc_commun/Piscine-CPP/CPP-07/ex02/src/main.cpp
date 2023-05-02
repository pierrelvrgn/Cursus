#include "../includes/Array.hpp"

int main()
{
	srand(time(NULL));

	const int count = 5;

	Array<int> test1(count);
	for (unsigned int i = 0; i < test1.size(); i++)
		test1[i] = rand() % 100 + 1;

	Array<int> test2(test1);

	Array<std::string> test3(count);
	test3[0] = "test1";
	test3[1] = "test2";
	test3[2] = "test3";
	test3[3] = "test4";
	test3[4] = "test5";

	Array<std::string> test4(test3);

	std::cout << "test1\ttest2\ttest3\ttest4" << std::endl << std::endl;
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test1[i] << "\t" << test2[i] << "\t" << test3[i] << "\t" << test4[i] << std::endl;

	for (unsigned int i = 0; i < test1.size(); i++)
		test1[i] = test1[i] * 10;

	for (unsigned int i = 0; i < test3.size(); i++)
		test3[i] = test3[i].append("_2").data();

	std::cout << "======================================" << std::endl << "test1\ttest2\ttest2\ttest4" << std::endl << std::endl;
	for (unsigned int i = 0; i < test2.size(); i++)
		std::cout << test1[i] << "\t" << test2[i] << "\t" << test3[i] << "\t" << test4[i] << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << test1[count] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
