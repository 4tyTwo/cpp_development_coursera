#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

bool sortFunc(const Person& p1, const Person& p2)
{
    if (p1.gender != p2.gender)
        return p1.gender < p2.gender;
    if (p1.is_employed != p2.is_employed)
        return p1.is_employed < p2.is_employed;
    return false;
}

void PrintStats(vector<Person> persons)
{
    sort(persons.begin(), persons.end(), sortFunc);
    auto first_employed_woman = find_if(persons.begin(), persons.end(), [](const Person& p)
        {
            return p.gender == Gender::FEMALE && p.is_employed == true;
        });
    auto first_man = find_if(persons.begin(), persons.end(), [](const Person& p)
        {
            return p.gender == Gender::MALE;
        });
    auto first_employed_man = find_if(persons.begin(), persons.end(), [](const Person& p)
        {
            return p.gender == Gender::MALE && p.is_employed == true;
        });

    if (first_employed_woman == persons.end())
        first_employed_woman = first_man;
    cout << "Median age = "                        << ComputeMedianAge(persons.begin(), persons.end())          << endl;
    cout << "Median age for females = "            << ComputeMedianAge(persons.begin(), first_man)            << endl;
    cout << "Median age for males = "              << ComputeMedianAge(first_man, persons.end())              << endl;
    cout << "Median age for employed females = "   << ComputeMedianAge(first_employed_woman, first_man)       << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), first_employed_woman) << endl;
    cout << "Median age for employed males = "     << ComputeMedianAge(first_employed_man, persons.end())     << endl;
    cout << "Median age for unemployed males = "   << ComputeMedianAge(first_man, first_employed_man)         << endl;
}

int main()
{
    vector<Person> persons = 
    {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
