#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Day {
    explicit Day(int v)
    {
        value = v;
    }
    int value;
};

struct Month {
    explicit Month(int v)
    {
        value = v;
    }
    int value;
};

struct Year {
    explicit Year(int v)
    {
        value = v;
    }
    int value;
};

struct FirstName {
    explicit FirstName(const string& v)
    {
        value = v;
    }
    string value;
};

struct LastName {
    explicit LastName(const string& v)
    {
        value = v;
    }
    string value;
};


class Student {
public:

    Student(const FirstName& f_name, const LastName& l_name, Day d, Month m, Year y) {
        first_name = f_name.value;
        last_name = l_name.value;
        day = d.value;
        month = m.value;
        year = y.value;
    }

    string getName() const
    {
        return first_name + " " + last_name;
    }

    string getBirthDay() const
    {
        return to_string(day) + "." + to_string(month) + "." + to_string(year);
    }


private:
    string first_name, last_name;
    int day, month, year;
};

class StudentVector {
public:

    StudentVector()
    {

    }

    StudentVector(int capacity, istream& in)
    {
        string first_name, last_name;
        int d, m , y;
        for (int i = 0; i < capacity; ++i) {
            in >> first_name >> last_name >> d >> m >> y;
            add({FirstName(first_name), LastName(last_name), Day(d), Month(m), Year(y)});
        }
    }

    string getName(int index) const
    {
        return data[index -1].getName();
    }

    string getBirthDay(int index) const
    {
        return data[index -1].getBirthDay();
    }

    void add(const Student& student)
    {
        data.push_back(student);
    }

    int maxIndex() const
    {
        return data.size() + 1;
    }
private:
    vector<Student> data;
};

int main() {
    int n, n_commands;
    cin >> n;
    StudentVector sv(n, cin);
    cin >> n_commands;
    string tmp;
    int m;
    for (int i = 0; i < n_commands; ++i) {
        cin >> tmp >> m;
        if (tmp == "name" && m <= n && m > 0) {
            cout << sv.getName(m) << endl;
        }
        else {
            if (tmp == "date" && m <= n && m > 0) {
                cout << sv.getBirthDay(m) << endl;
            }
            else {
                cout << "bad request" << endl;
            }
        }
    }
    return 0;
}
