#include "phone_number.h"
#include "test_runner.h"

using namespace std;

void TestNumberParsing()
{
	{
		string number = "+7-495-111-22-33";
		AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
	}
	{
		string number = "+7-495-1112233";
		AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
	}
	{
		string number = "+323-22-460002";
		AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
	}
	{
		string number = "+1-2-coursera-cpp";
		AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
	}
}

void TestWrongFormat()
{
	{
		string number = "1-2-333";
		try
		{
			AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
		}
		catch (invalid_argument& e)
		{
			// ok
		}
	}
	{
		string number = "+7-1233";
		try
		{
			AssertEqual(PhoneNumber(number).GetInternationalNumber(), number);
		}
		catch (invalid_argument& e)
		{
			// ok
		}
	}
}

int main()
{
	TestRunner runner;
	runner.RunTest(TestWrongFormat, "TestWrongFormat");
	runner.RunTest(TestNumberParsing, "TestNumberParsing");
	system("PAUSE");
	return 0;
}