#include <iostream>
#include <algorithm>

#include "test_runner.h"
#include "sum_reverse_sort.h"

using namespace std;

void TestSum()
{
	AssertEqual(Sum(2, 2), 2 + 2);
	AssertEqual(Sum(2, 0), 2 + 0);
	AssertEqual(Sum(0, 0), 0 + 0);
	AssertEqual(Sum(-2, -1), -2 + -1);
}

void TestReverse()
{
	{
		string source = "abcdefg";
		auto expected = source;
		reverse(expected.begin(), expected.end());
		AssertEqual(Reverse(source), expected);
	}
	{
		string source = "";
		auto expected = source;
		reverse(expected.begin(), expected.end());
		AssertEqual(Reverse(source), expected);
	}
	{
		string source = "a";
		auto expected = source;
		reverse(expected.begin(), expected.end());
		AssertEqual(Reverse(source), expected);
	}
}


void TestSort()
{
	{
		vector<int> source = { 1, 2, 3 };
		auto expected = source;
		sort(expected.begin(), expected.end());
		Sort(source);
		AssertEqual(source, expected);
	}
	{
		vector<int> source = { 8, 2, 9, 0 };
		auto expected = source;
		sort(expected.begin(), expected.end());
		Sort(source);
		AssertEqual(source, expected);
	}
	{
		vector<int> source = {};
		auto expected = source;
		sort(expected.begin(), expected.end());
		Sort(source);
		AssertEqual(source, expected);
	}
}

int Sum(int x, int y)
{
	return x + y;
}

string Reverse(string s)
{
	reverse(s.begin(), s.end());
	return s;
}
void Sort(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}


//int main()
//{
//	TestRunner runner;
//	runner.RunTest(TestSum, "TestSum");
//	runner.RunTest(TestReverse, "TestReverse");
//	runner.RunTest(TestSort, "TestSort");
//	return 0;
//}
