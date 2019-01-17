#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s)
{
    os << "{";
    bool first = true;
    for (const auto& x : s)
    {
        if (!first)
            os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s)
{
    os << "{";
    bool first = true;
    for (const auto& x : s)
    {
        if (!first)
            os << ", ";
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m)
{
    os << "{";
    bool first = true;
    for (const auto& kv : m)
    {
        if (!first)
            os << ", ";
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {})
{
    if (t != u)
    {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
        os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint)
{
    AssertEqual(b, true, hint);
}

class TestRunner 
{
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name)
    {
        try
        {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e)
        {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...)
        {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0)
        {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
        }
    }

private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c)
{
    if (a != 0)
    {
        // thus equation IS quadratic
        double d = (b * b) - (4 * a * c);
        if (d == 0)
                return 1;
        if (d > 0)
            return 2;
        else
            return 0;
    }
    else
        if (b != 0)
            return 1;
    return 0;
}

/// Tests

void TestNonQuadratic()
{
    const string hint = "A = 0";
    AssertEqual(GetDistinctRealRootCount(0, 5, -3), 1, hint);
    AssertEqual(GetDistinctRealRootCount(0, 4,  2), 1, hint);
    AssertEqual(GetDistinctRealRootCount(0, 3, -9), 1, hint);
}

void TestDegenerateCase()
{
    const string hint = "Degenerate case";
    AssertEqual(GetDistinctRealRootCount(0, 0,  1), 0, hint);
    AssertEqual(GetDistinctRealRootCount(0, 0, -1), 0, hint);
}

void TestZeroDiscriminant()
{
    const string hint = "Zero Discriminant";
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, hint);
    AssertEqual(GetDistinctRealRootCount(8, 8, 2), 1, hint);
}

void TestNegativeDiscriminant()
{
    const string hint = "Negative Discriminant";
    AssertEqual(GetDistinctRealRootCount(9, 2, 1), 0, hint);
    AssertEqual(GetDistinctRealRootCount(9, 8, 2), 0, hint);
}

void TestCommonCase()
{
    const string hint = "Common case";
    AssertEqual(GetDistinctRealRootCount(4, 9, 2), 2, hint);
    AssertEqual(GetDistinctRealRootCount(4, 2, 0), 2, hint);
}

void TestPureQuadratic()
{
    const string hint = "B = 0";
    AssertEqual(GetDistinctRealRootCount(4, 0,  2), 0, hint);
    AssertEqual(GetDistinctRealRootCount(4, 0,  0), 1, hint);
    AssertEqual(GetDistinctRealRootCount(4, 0, -1), 2, hint);
}


int main()
{
  TestRunner runner;
  runner.RunTest(TestCommonCase, "TestCommonCase");
  runner.RunTest(TestNonQuadratic, "TestNonQuadratic");
  runner.RunTest(TestPureQuadratic, "TestPureQuadratic");
  runner.RunTest(TestDegenerateCase, "TestDegenerateCase");
  runner.RunTest(TestZeroDiscriminant, "TestZeroDiscriminant");
  runner.RunTest(TestNegativeDiscriminant, "TestNegativeDiscriminant");
  return 0;
}
