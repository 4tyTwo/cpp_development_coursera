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

bool IsPalindrom(string st) 
{
    int length = st.length();
    for (int i = 0; i < length / 2; ++i)
        if (st[i] != st[length -1 - i])
            return false;
    return true;
}

void TestEmptyString()
{
    AssertEqual(IsPalindrom(""), true, "empty string should be a palindrom");
}

void TestSingleChar()
{
    AssertEqual(IsPalindrom("r"), true, "one char string should be a palindrom");
}

void TestFullSpacesString()
{
    AssertEqual(IsPalindrom(" "), true, "space string should be a palindrom");
    AssertEqual(IsPalindrom("  "), true, "space string should be a palindrom");
    AssertEqual(IsPalindrom("                   "), true, "space string should be a palindrom");
}

void TestBasicPalindromes()
{
    string tested = "madam";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
    tested = "level";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
    tested = "wasitacaroracatisaw";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
}

void TestBasicNonPalindromes()
{
    string tested = "madman";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
    tested = "palindrome";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
    tested = "totalynotapalindrom";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
}

void TestEvenLengthStrings()
{
    string tested = "raar";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
}

void TestStringWithDelimetres()
{
    string tested = "ra ar";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
    tested = "ra,ar";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
    tested = "ra, ,ar";
    AssertEqual(IsPalindrom(tested), true,  tested +" should be a palindrom");
    tested = "а роза упала на лапу азора";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
    tested = "а,роза,упала,на,лапу,азора";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
}

void TestEarlyReturn()
{
    string tested = "op rt po";
    AssertEqual(IsPalindrom(tested), false,  tested + " shouldn't be a palindrom");
    tested = "iooooooooo";
    AssertEqual(IsPalindrom(tested), false,  tested + " shouldn't be a palindrom");
    tested = "iool";
    AssertEqual(IsPalindrom(tested), false,  tested + " shouldn't be a palindrom");
    tested = "looi";
    AssertEqual(IsPalindrom(tested), false,  tested + " shouldn't be a palindrom");
    tested = "ra,   raguygar   ,ar";
    AssertEqual(IsPalindrom(tested), false,  tested +" shouldn't be a palindrom");
}

void TestNewLine()
{
    string tested = "madam\n";
    AssertEqual(IsPalindrom(tested), false,  tested + " shouldn't be a palindrom");
    tested = "\nmadam\n";
    AssertEqual(IsPalindrom(tested), true,  tested + " should be a palindrom");
}

int main()
{
    TestRunner runner;
    runner.RunTest(TestNewLine, "TestNewLine");
    runner.RunTest(TestSingleChar, "TestSingleChar");
    runner.RunTest(TestEmptyString, "TestEmptyString");
    runner.RunTest(TestEarlyReturn, "TestEarlyReturn");
    runner.RunTest(TestFullSpacesString, "TestFullSpacesString");
    runner.RunTest(TestBasicPalindromes, "TestBasicPalindromes");
    runner.RunTest(TestEvenLengthStrings, "TestEvenLengthStrings");
    runner.RunTest(TestBasicNonPalindromes, "TestBasicNonPalindromes");
    runner.RunTest(TestStringWithDelimetres, "TestStringWithDelimetres");
    return 0;
}
