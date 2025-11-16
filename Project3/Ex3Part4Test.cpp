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

void addElementsToVector(Vector& v, const int elements[], const int numberOfElements)
{
	int element;
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		v.push_back(elements[i]);
	}
}

std::string getVectorElementsString(Vector& v)
{
	std::string result = "";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		result += std::to_string(v[i]) + ",";
	}
	if (v.size() > 0)
		result = result.substr(0, result.length() - 1);
	return result;
}


int test4()
{

	try
	{
		// Tests Ex3 part 4 - operator[] , assign, resize

		cout <<
			"********************************************\n" <<
			"Test 4 - resize, assign, operator[] \n" <<
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
			cout << "Expected:\n" << expected << endl;
			cout << "Got     :\n" << got << std::endl;
			std::cout << " \n" << endl;
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

		expected = "v1: 1,2,3,4,5,6,7,8,9,10\n";
		expected += "v2: 11,22,33,44,55,66,77,88,99,110";
		got = "v1: " + getVectorElementsString(v1) + "\nv2: " + getVectorElementsString(v2);
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
			"\nAccessing element v1[5] ... \n" << endl;

		expected = "6";
		got = std::to_string(v1[5]);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3114");
			std::cout << " \n" << endl;
			return 3114;
		}

		cout <<
			"\nAccessing element v2[9] ... \n" << endl;

		expected = "110";
		got = std::to_string(v2[9]);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3114");
			std::cout << " \n" << endl;
			return 3114;
		}

		cout <<
			"\nAccessing element v2[10] ... \n" << endl;

		expected = "11";
		got = std::to_string(v2[10]);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3115");
			std::cout << " \n" << endl;
			return 3115;
		}

		cout <<
			"\nAccessing element v1[-1] ... \n" << endl;

		expected = "11";
		got = std::to_string(v2[-1]);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3116");
			std::cout << " \n" << endl;
			return 3116;
		}

		try
		{


			cout <<
				"\nInitializing Vector v3, using copy constructor with v1  \n" << endl;

			Vector v3(v1);

			expected = "v1: 1,2,3,4,5,6,7,8,9,10\n";
			expected += "v3: 1,2,3,4,5,6,7,8,9,10";
			got = "v1: " + getVectorElementsString(v1) + "\nv3: " + getVectorElementsString(v3);
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
				"\ncopying v2 to v3, using operator= (v3 = v2) ... \n" << endl;
			v3 = v2;

			expected = "v2: 11,22,33,44,55,66,77,88,99,110\n";
			expected += "v3: 11,22,33,44,55,66,77,88,99,110";
			got = "v2: " + getVectorElementsString(v2) + "\nv3: " + getVectorElementsString(v3);
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
		}
		catch (...)
		{
			std::cerr << "\033[1;31mTest crashed\033[0m\n \n" << endl;
			std::cerr << "\033[1;31mFAILED: The program crashed, check the following things:\n\033[0m\n \n" <<
				"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
				"3. Did you remember to initialize array before accessing it?\n4.Check copy constructor";
			return 2;
		}

		cout <<
			"\ncalling v1.assign(999)... \n" << endl;
		v1.assign(999);
		expected = "v1: 999,999,999,999,999,999,999,999,999,999";
		got = "v1: " + getVectorElementsString(v1);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3117");
			std::cout << " \n" << endl;
			return 3117;
		}

		cout <<
			"\ncalling v2.resize(15, 1234)... \n" << endl;
		v2.resize(15,1234);
		expected = "v2: 11,22,33,44,55,66,77,88,99,110,1234,1234,1234,1234,1234";
		got = "v2: " + getVectorElementsString(v2);
		if (got == expected)
		{
			cout << "\033[1;32mTest Passed\033[0m\n \n" << endl;
		}
		else
		{
			cout << "\033[1;31mTest Failed\033[0m\n \n" << endl;
			cout << "Expected: " << expected << endl;
			cout << "Got     : " << got << std::endl;
			system("./printMessage 3118");
			std::cout << " \n" << endl;
			return 3118;
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
		"Part 4 - operator[], resize(), assign() \n" <<
		"###################\n" << std::endl;

	int testResult = test4();

	cout << (testResult == 0 ? "\033[1;32m \n****** Ex3 Part 4 Tests Passed ******\033[0m\n \n" : "\033[1;31mEx3 Part 4 Tests Failed\033[0m\n \n") << endl;

	return testResult;
}