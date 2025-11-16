#include "Vector.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

std::string getVectorString(const Vector& v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

int test1Basic()
{
	try
	{
		// Tests Ex3 part 1 - Vector Constructor and Destructor

		cout <<
			"********************\n" <<
			"Test 1 - CTOR, DTOR \n" <<
			"********************\n" << endl;

		cout <<
			"Initializing Vector v1 with n=10: ... \n" << endl;

		Vector v1(10);
		std::string expected = "[capacity: 10, size: 0, resize factor: 10]";
		std::string got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3101");
			std::cout << " \n" << endl;
			return 3101;
		}

		cout <<
			"Checking if v1 is empty ... \n" << endl;
		

		expected = "true";
		got = v1.empty() ? "true" : "false";

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3102");
			std::cout << " \n" << endl;
			return 3102;
		}

		cout <<
			"Initializing Vector v2 with n=1 ... \n" << endl;

		Vector v2(1);
		expected = "[capacity: 2, size: 0, resize factor: 2]";
		got = getVectorString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3101");
			std::cout << " \n" << endl;
			return 3101;
		}

		cout <<
			"Checking if v2 is empty ... \n" << endl;


		expected = "true";
		got = v2.empty() ? "true" : "false";

		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3102");
			std::cout << " \n" << endl;
			return 3102;
		}

		cout <<
			"Initializing Vector v3 with n=-42 ... \n" << endl;

		Vector v3(-42);
		expected = "[capacity: 2, size: 0, resize factor: 2]";
		got = getVectorString(v3);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3101");
			std::cout << " \n" << endl;
			return 3101;
		}

		cout <<
			"Checking if v3 is empty ... \n" << endl;


		expected = "true";
		got = v3.empty() ? "true" : "false";
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3102");
			std::cout << " \n" << endl;
			return 3102;
		}
	} 
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n.\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}


	return 0;

}


int main()
{
	std::cout <<
		"###########################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 1 - CTOR & DTOR\n" <<
		"###########################\n" << std::endl;

	int testResult = test1Basic();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex3 Part 1 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx3 Part 1 Tests Failed\033[0m\n \n") << endl;

	return testResult ;
}