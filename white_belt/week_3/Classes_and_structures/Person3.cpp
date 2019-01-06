#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:

    Person(string first_name, string last_name, int birth_year)
    {
        this->birth_year = birth_year;
        first_name_changes[birth_year] = first_name;
        last_name_changes[birth_year]  = last_name;
    }
    void ChangeFirstName(int year, const string& first_name)
    {
        if (year < birth_year)
            return;
        first_name_changes[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name)
    {
        if (year < birth_year)
            return;
        last_name_changes[year] = last_name;
    }

    string GetFullName(int year) const
    {
        if (year < birth_year)
            return "No person";
        string first_name = getLastKnownName(first_name_changes, year);
        string last_name = getLastKnownName(last_name_changes, year);
        vector<string> parts = resolveFullName(first_name, last_name);
        return concatOutput(parts);
    }

    string GetFullNameWithHistory(int year) const
    {
        if (year < birth_year)
            return "No person";
        string first_name = getLastKnownName(first_name_changes, year);
        string last_name = getLastKnownName(last_name_changes, year);
        vector<string> parts = resolveFullName(first_name, last_name);
        parts.insert(parts.begin() + 1, formatNamesVector(getHistory(first_name_changes, year, first_name)));
        parts.insert(parts.begin() + 4, formatNamesVector(getHistory(last_name_changes, year, last_name)));
        return concatOutput(parts);
    }

private:

    string concatOutput(vector<string>& parts) const
    {
        if (parts[2] == "with unknown" && parts[3] == "first name")
            swap(parts[1], parts[4]); // shady
        string res;
        for (int i = 0; i < parts.size(); ++i) {
            if (i > 0 && !parts[i].empty()) {
                res += " ";
            }
            res += parts[i];
        }
        return res;
    }

    string formatNamesVector(const vector<string>& names) const
    {
        if (names.empty())
            return "";
        string res = "(";
        for (int i = 0; i < names.size(); ++i) {
            if (i > 0)
                res += ", ";
            res += names[i];
        }
        return res + ")";
    }

    vector<string> getHistory(const map<int, string>& changes, int year, string curr_name) const
    {
        vector<string> history;
        for (auto iter = changes.rbegin(); iter != changes.rend(); ++iter) {
            if (iter->first < year) {
                if (!history.empty()) {
                    if(iter->second != history.back())
                        history.push_back(iter->second);
                }
                else {
                    if (iter->second != curr_name)
                        history.push_back(iter->second);
                }
            }
        }
        return history;
    }

    vector<string> resolveFullName(const string& first_name, const string& last_name) const
    {
        if (first_name == "" && last_name == "")
            return {"Incognito", "", ""};
        if (first_name == "") 
            return {last_name, "with unknown" , "first name"};
        if (last_name == "") 
            return {first_name,  "with unknown", "last name"};
        return {first_name, "", last_name};
    }

    string getLastKnownName(const map<int, string>& changes, int year) const
    {
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
    int birth_year;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
