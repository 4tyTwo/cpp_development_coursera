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

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        first_name_changes[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name)
    {
        last_name_changes[year] = last_name;
    }

    string GetFullName(int year)
    {
        string first_name = get_last_known_name(first_name_changes, year);
        string last_name = get_last_known_name(last_name_changes, year);
        return resolve_full_name(first_name, last_name);
    }

private:

    string resolve_full_name(const string& first_name, const string& last_name) {
        if (first_name == "" && last_name == "")
            return "Incognito";
        if (first_name == "") 
            return last_name + " with unknown first name";
        if (last_name == "") 
            return first_name + " with unknown last name";
        return first_name + " " + last_name;
    }

    string get_last_known_name(const map<int, string>& changes, int year) {
        string name = "";
        for (auto item : changes) {
            if (item.first <= year)
                name = item.second;
            else
                return name;
        }
        return name;
    }

    map<int, string> first_name_changes, last_name_changes;
};


void TestSimpleAdd()
{
    Person p;
    p.ChangeFirstName(1988, "Alice");
    p.ChangeLastName(1988, "Glass");
    AssertEqual(p.GetFullName(1988), "Alice Glass", "Name hasn't changed");
    AssertEqual(p.GetFullName(1989), "Alice Glass", "Name is not visible further");
}

void TestOverride()
{
    Person p;
    int year = 2006;
    p.ChangeFirstName(year, "Alice");
    p.ChangeLastName(year,  "Glass");
    AssertEqual(p.GetFullName(year), "Alice Glass", "Name is not displayed");
    year = 2015;
    p.ChangeFirstName(year, "Edith");
    p.ChangeLastName(year,  "Frances");
    AssertEqual(p.GetFullName(year), "Edith Frances", "Name hasn't changed");
}

void TestEmpty()
{
    Person p;
    AssertEqual(p.GetFullName(1988), "Incognito", "Non incognito on empty");
    p.ChangeFirstName(1988, "Alice");
    AssertEqual(p.GetFullName(1987), "Incognito", "Name is displayed before it's announcement");
}

void TestUnknown()
{
    int year = 1988;
    {
        Person p;
        p.ChangeFirstName(year, "Alice");
        AssertEqual(p.GetFullName(year), "Alice with unknown last name", "Last name is not unknown");
    }
    {
        Person p;
        p.ChangeLastName(year, "Glass");
        AssertEqual(p.GetFullName(year), "Glass with unknown first name", "First name is not unknown");
    }
}


int main()
{
    TestRunner runner;
    runner.RunTest(TestSimpleAdd, "TestSimpleAdd");
    runner.RunTest(TestOverride, "TestOverride");
    runner.RunTest(TestUnknown, "TestUnknown");
    runner.RunTest(TestEmpty, "TestEmpty");
    return 0;
}
