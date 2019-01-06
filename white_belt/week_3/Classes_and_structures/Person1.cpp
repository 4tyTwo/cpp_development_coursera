#include <string>
#include <map>

using namespace std;

class Person {
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
