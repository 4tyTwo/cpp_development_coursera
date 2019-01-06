#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;


const vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int num_months = 12;

int curr_month = 0;

void test(vector<vector<string>>& plan);

int next_month() {
    return (curr_month + 1) % num_months;
}


void add(vector<vector<string>>& plan, int day, string buisness) {
    plan[day - 1].push_back(buisness);
}

void next(vector<vector<string>>& plan) {
    vector<vector<string>> new_plan(plan);
    new_plan.resize(days_in_months[next_month()]);
    if (new_plan.size() < plan.size()) {
        for (int i = plan.size() - 1; i >= new_plan.size(); --i) {
            new_plan[new_plan.size() - 1 ].insert(end(new_plan[new_plan.size() - 1 ]), begin(plan[i]), end(plan[i]));
        }
    }
    curr_month = next_month();
    plan = new_plan;
}

void dump(const vector<vector<string>>& plan, int day) {
    cout << plan[day - 1].size() << " ";
    for (auto s : plan[day - 1]) {
        cout << " " << s ;
    }
    cout << endl;
}

int main() {
    int n, day;
    // cin >> n;
    n = 0;
    vector<vector<string>> plan(days_in_months[curr_month]);
    test(plan);
    string tmp, buisness;
    for (int i = 0 ; i < n; ++i) {
        cin >> tmp;
        if (tmp == "ADD") {
            cin >> day;
            cin >> buisness;
            add(plan, day, buisness);
        }
        if (tmp == "NEXT") {
            next(plan);
        }
        if (tmp == "DUMP") {
            cin >> day;
            dump(plan, day);
        }
    }
    return 0;
}

void test1(vector<vector<string>>& plan) {
    add(plan, 5, "Salary");
    add(plan, 31, "Walk");
    add(plan, 30, "WalkPrep");
    next(plan);
    dump(plan, 5);
    dump(plan, 28);
    next(plan);
    dump(plan, 31);
    dump(plan, 30);
    dump(plan, 28);
    add(plan, 28, "Payment");
    dump(plan, 28);
}

void log(const vector<vector<string>>& plan, ofstream& myfile) {
    map<int, string> months = {{0, "January"}, {1, "February"}, {2, "March"}, {3, "April"}, {4, "May"}, {5, "June"},
        {6, "July"}, {7, "August"}, {8, "September"}, {9, "October"}, {10, "November"}, {11, "December"}};
    myfile << "Current month is " << months[curr_month] << ", it has " << days_in_months[curr_month] << " days" << endl;
    myfile << "Planner for this month:" << endl;
    for (int i = 0; i < plan.size(); ++i) {
        myfile << "Day #" << i + 1 << ":";
        for (auto s : plan[i]) {
            myfile << " " << s ;
        }
        myfile << endl;
    }
    myfile << endl;
    myfile << endl;
    myfile << endl;
}

void test(vector<vector<string>>& plan) {
    ofstream myfile;
    myfile.open ("planner.txt");
    add(plan, 31, "First");
    add(plan, 30, "Second");
    add(plan, 29, "Third");
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    log(plan, myfile);
    next(plan);
    myfile.close();
}
