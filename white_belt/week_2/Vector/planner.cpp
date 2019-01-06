#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <map>

using namespace std;

const vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int num_months = 12;

int curr_month = 0;

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
    cin >> n;
    vector<vector<string>> plan(days_in_months[curr_month]);
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
