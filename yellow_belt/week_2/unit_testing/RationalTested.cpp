#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

// class Rational {
// public:
//     Rational()
//     {
//         numerator = 0;
//         denominator = 1;
//     }
//     Rational(int num, int denom)
//     {
//         if (num == 0) {
//             numerator = num;
//             denominator = 1;
//             return;
//         }
//         int divisor = gcd(num, denom);
//         num/=divisor;
//         denom/=divisor;
//         if (num < 0 && denom < 0) {
//             num   = abs(num);
//             denom = abs(denom);
//         }
//         else {
//             if (denom < 0) {
//                 denom = abs(denom);
//                 num = - num;
//             }
//         }
//         this->numerator = num;
//         this->denominator = denom;
//     }

//     int Numerator() const
//     {
//         return numerator;
//     }
//     int Denominator() const
//     {
//         return denominator;
//     }

// private:
//     int gcd(int a, int b) 
//     {
//         return b == 0 ? a : gcd(b, a % b);
//     }
//     int numerator, denominator;
// };

void TestDefaultConstructor()
{
    Rational r;
    AssertEqual(r.Numerator(), 0, "Default Numerator is not 0");
    AssertEqual(r.Denominator(), 1, "Default Denominator is not 1");
}

void TestReduction()
{
    const string hint = "Rational didn't reduced";
    {
        Rational r(4, 2);
        AssertEqual(r.Numerator(), 2, hint);
        AssertEqual(r.Denominator(), 1, hint);
    }
    {
        Rational r(1, 7);
        AssertEqual(r.Numerator(), 1, hint);
        AssertEqual(r.Denominator(), 7, hint);
    }
}

void TestNegative()
{
    const string hint = "Incorrect negative rational constructor";
    {
        Rational r(-1, 3);
        AssertEqual(r.Numerator(), -1, hint);
        AssertEqual(r.Denominator(), 3, hint);
    }
    {
        Rational r(1, -3);
        AssertEqual(r.Numerator(), -1, hint);
        AssertEqual(r.Denominator(), 3, hint);
    }
    {
        Rational r(-1, -3);
        AssertEqual(r.Numerator(), 1, hint);
        AssertEqual(r.Denominator(), 3, hint);
    }
}

void TestZero()
{
    const string hint = "Incorrect zero rational constructor";
    {
        Rational r(0, 3);
        AssertEqual(r.Numerator(), 0, hint);
        AssertEqual(r.Denominator(), 1, hint);
    }
    {
        Rational r(0, -3);
        AssertEqual(r.Numerator(), 0, hint);
        AssertEqual(r.Denominator(), 1, hint);
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestReduction, "TestReduction");
    runner.RunTest(TestNegative, "TestNegative");
    runner.RunTest(TestZero, "TestZero");
    return 0;
}
