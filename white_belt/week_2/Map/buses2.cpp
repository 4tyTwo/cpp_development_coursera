#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int curr_number = 1;

int get_new_bus_number() {
    return curr_number++;
}

void new_bus(map<vector<string>, int>& catalog, vector<string> stops) {
    if (catalog.count(stops) > 0) {
        cout << "Already exists for ";
    }
    else {
        catalog[stops] = get_new_bus_number();
        cout << "New bus ";
    }
    cout << catalog[stops] << endl;
}

int main() {
    int n, stop_count;
    cin >> n;
    string tmp;
    vector<string> stops;
    map<vector<string>, int> catalog;
    for (int i = 0 ; i < n; ++i) {
        cin >> stop_count;
        stops.resize(stop_count);
        for (int j = 0; j < stop_count; ++j) {
            cin >> stops[j];
        }
        new_bus(catalog, stops);
    }
    return 0;
}
