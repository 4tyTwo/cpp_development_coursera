#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int curr_number = 1;

int get_new_bus_number() {
    return curr_number++;
}

void new_bus(map<set<string>, int>& catalog, vector<string> stops) {
    set<string> stops_set(stops.begin(), stops.end());
    if (catalog.count(stops_set) > 0) {
        cout << "Already exists for ";
    }
    else {
        catalog[stops_set] = get_new_bus_number();
        cout << "New bus ";
    }
    cout << catalog[stops_set] << endl;
}

int main() {
    int n, stop_count;
    cin >> n;
    string tmp;
    vector<string> stops;
    map<set<string>, int> catalog;
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
