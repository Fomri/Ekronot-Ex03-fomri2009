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

std::string getPoppedElementsString(Vector& v, const int numberOfElements)
{
	std::string result = "";
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		element = v.pop_back();
		if (element < 0)
		{
			return "ERROR " + std::to_string(element);
		}
		result += std::to_string(element);
	}
	return result;
}

int test2AddElements()
{
	bool result = false;

	try
	{
		// Tests Ex3 part 2 - push_back(), pop_back(), reserve()

		cout <<
			"********************************************\n" <<
			"Test 2 - push_back(), pop_back(), reserve() \n" <<
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
			"Adding 3 elements to vector v1 ... \n" << endl;

		addRandomElementsToVector(v1, 3);

		expected = "[capacity: 5, size: 3, resize factor: 5]";
		got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3103");
			std::cout << " \n" << endl;
			return 3103;
		}

		cout <<
			"Checking if v1 is empty ... \n" << endl;


		expected = "false";
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
			system("./printMessage 3104");
			std::cout << " \n" << endl;
			return 3104;
		}

		cout <<
			"Adding 3 more elements to vector v1 ... \n" << endl;
		addRandomElementsToVector(v1, 3);

		expected = "[capacity: 10, size: 6, resize factor: 5]";
		got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3105");
			std::cout << " \n" << endl;
			return 3105;
		}

		cout <<
			"Adding 24 more elements to vector v1 ... \n" << endl;
		addRandomElementsToVector(v1, 24);

		expected = "[capacity: 30, size: 30, resize factor: 5]";
		got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3105");
			std::cout << " \n" << endl;
			return 3105;
		}

		cout <<
			"Popping 20 elements from vector ... \n" << endl;
		getPoppedElementsString(v1, 20);

		expected = "[capacity: 30, size: 10, resize factor: 5]";
		got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3106");
			std::cout << " \n" << endl;
			return 3106;
		}

		cout <<
			"Checking if v1 is empty ... \n" << endl;

		expected = "false";
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
			system("./printMessage 3104");
			std::cout << " \n" << endl;
			return 3104;
		}

		cout <<
			"Popping 10 elements from vector ... \n" << endl;
		getPoppedElementsString(v1, 10);

		expected = "[capacity: 30, size: 0, resize factor: 5]";
		got = getVectorString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3106");
			std::cout << " \n" << endl;
			return 3106;
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
			system("./printMessage 3107");
			std::cout << " \n" << endl;
			return 3107;
		}

		cout <<
			"Popping one more element from vector ... \n" << endl;

		expected = "ERROR -9999";
		got = getPoppedElementsString(v1, 1); 
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3108");
			std::cout << " \n" << endl;
			return 3108;
		}

		cout <<
			"Initializing Vector v2 with n=5 ... \n" << endl;

		Vector v2(5);
		expected = "[capacity: 5, size: 0, resize factor: 5]";
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
			"Calling v2.reserve(23) ... \n" << endl;

		v2.reserve(23);

		expected = "[capacity: 25, size: 0, resize factor: 5]";
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
			system("./printMessage 3109");
			std::cout << " \n" << endl;
			return 3109;
		}

		cout <<
			"Calling v2.reserve(12) ... \n" << endl;

		v2.reserve(12);

		expected = "[capacity: 25, size: 0, resize factor: 5]";
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
			system("./printMessage 3110");
			std::cout << " \n" << endl;
			return 3110;
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
		"###########################\n" <<
		"Exercise 3 - Vector\n" <<
		"Part 2 - push_back, pop_back, reserve() \n" <<
		"###########################\n" << std::endl;

	int testResult = test2AddElements();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex3 Part 2 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx3 Part 2 Tests Failed\033[0m\n \n") << endl;
	
	return testResult ;
}