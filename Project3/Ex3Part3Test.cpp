#include "Vector.h"
#include <iostream>
#include <string>
#include <random>

using std::cout;
using std::endl;

// gets a random number between a range of numbers
int getRandomInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	auto random_integer = uni(rng);
	return random_integer;
}

std::string getVectorString(const Vector& v)
{
	return
		"[capacity: " + std::to_string(v.capacity()) +
		", size: " + std::to_string(v.size()) +
		", resize factor: " + std::to_string(v.resizeFactor()) + "]";
}

void addRandomElementsToVector(Vector& v, const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		element = getRandomInt(0, 100000);
		v.push_back(element);
	}
}

void addElementsToVector(Vector& v, const int elements[], const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		v.push_back(elements[i]);
	}
}

int test3Big3()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 3 - Big 3

		cout <<
			"********************************************\n" <<
			"Test 3 - Copy CTOR, operator= \n" <<
			"********************************************\n" << endl;

		cout <<
			"Initializing Vector v1 with n=5 ... \n" << endl;

		Vector v1(5);
		std::string expected = "[capacity: 5, size: 0, resize factor: 5]";
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
			"Initializing Vector v2 with n=7 ... \n" << endl;

		Vector v2(7);
		expected = "[capacity: 7, size: 0, resize factor: 7]";
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
			"Adding 10 elements to vector v1 (1,2, ... ,10) ... \n" << endl;

		const int v1elements[] = { 1,2,3,4,5,6,7,8,9,10 };
		addElementsToVector(v1, v1elements, 10);

		cout <<
			"Adding 10 elements to vector v2 (11,22, ... ,99,110) ... \n" << endl;

		const int v2elements[] = { 11,22,33,44,55,66,77,88,99,110 };
		addElementsToVector(v2, v2elements, 10);
		expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
		expected += "v2: [capacity: 14, size: 10, resize factor: 7]";
		got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			system("./printMessage 3105");
			std::cout << " \n" << endl;
			return 3105;
		}

		cout <<
			"Initializing Vector v3, using copy constructor with v1 ... \n" << endl;

		try
		{

			Vector v3(v1);

			expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
			expected += "v3: [capacity: 10, size: 10, resize factor: 5]";
			got = "v1: " + getVectorString(v1) + "\nv3: " + getVectorString(v3);
			if (got == expected)
			{
				cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			}
			else
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected:\n" << expected << endl;
				cout << "Got     :\n" << got << std::endl;
				std::cout << " \n" << endl;
				system("./printMessage 3111");
				std::cout << " \n" << endl;
				return 3111;
			}

			cout <<
				"Adding 3 elements to v3 ... \n" << endl;
			addRandomElementsToVector(v3, 3);

			expected = "v1: [capacity: 10, size: 10, resize factor: 5]\n";
			expected += "v3: [capacity: 15, size: 13, resize factor: 5]";
			got = "v1: " + getVectorString(v1) + "\nv3: " + getVectorString(v3);
			if (got == expected)
			{
				cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			}
			else
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected:\n" << expected << endl;
				cout << "Got     :\n" << got << std::endl;
				std::cout << " \n" << endl;
				system("./printMessage 3112");
				std::cout << " \n" << endl;
				return 3112;
			}
		}
		catch (...)
		{
			std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
			std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
				"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
				"3. Did you remember to initialize array before accessing it?\n4.Check copy constructor";
			return 2;
		}

		// Self-assignment check
		cout <<
			"Copying v1 to v1, using operator= (v1 = v1) ... \n" << endl;
		{
			std::string before = getVectorString(v1);
			v1 = v1;
			std::string after = getVectorString(v1);
			if (after == before)
			{
				cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
			}
			else
			{
				cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
				cout << "Expected: " << before << endl;
				cout << "Got     : " << after << endl;
				system("./printMessage 3113");
				cout << " \n" << endl;
				return 3113;
			}
		}

		cout <<
			"Copying v2 to v1, using operator= (v1 = v2) ... \n" << endl;
		v1 = v2;

		expected = "v1: [capacity: 14, size: 10, resize factor: 7]\n";
		expected += "v2: [capacity: 14, size: 10, resize factor: 7]";
		got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			system("./printMessage 3113");
			std::cout << " \n" << endl;
			return 3113;
		}

		cout <<
			"Adding 9 elements to v2 ... \n" << endl;
		addRandomElementsToVector(v2, 9);

		expected = "v1: [capacity: 14, size: 10, resize factor: 7]\n";
		expected += "v2: [capacity: 21, size: 19, resize factor: 7]";
		got = "v1: " + getVectorString(v1) + "\nv2: " + getVectorString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
			system("./printMessage 3112");
			std::cout << " \n" << endl;
			return 3112;
		}
	}
	catch (...)
	{
		std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
		std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		return 2;
	}

	return 0;

}

int main()
{
	std::cout <<
		"###################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 3 - Big 3 \n" <<
		"###################\n" << std::endl;

	int testResult = test3Big3();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex3 Part 3 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx3 Part 3 Tests Failed\033[0m\n \n") << endl;

	return testResult;
}