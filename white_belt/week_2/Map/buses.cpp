#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> bus_order;

map<string, vector<string>> inverse(const map<string, vector<string>>& catalog) {
    // creates map with stops as a key and buses going throught it as values
    map<string, vector<string>> res;
    for (auto item : catalog) {
        for (auto stop : item.second) {
            res[stop].push_back(item.first);
        }
    }
    return res;
}

void new_bus(map<string, vector<string>>& catalog, string bus, vector<string> stops) {
    bus_order.push_back(bus);
    catalog[bus] = stops;
}

void buses_for_stop(const map<string, vector<string>>& catalog, string stop, string exclude) {
    map<string, vector<string>> inv = inverse(catalog);
    int i = 0;
    if (inv.count(stop) > 0) {
        vector<string> buses = inv[stop];
        for (auto bus : bus_order) {
            if (bus != exclude && count(buses.begin(), buses.end(), bus) > 0) {
                ++i;
                cout << bus << " ";
            }
        }
        if (i == 0) {
            cout << "no interchange";
        }
    }
    else {
        cout << "No stop";
    }
    cout << endl;
}

void stops_for_bus(const map<string, vector<string>>& catalog, string bus) {
    // passing here regular catalog bus -> stops
    if (catalog.count(bus) > 0) {
        for (auto s : catalog.find(bus)->second) {
            cout << "Stop " << s << ": ";
            buses_for_stop(catalog, s, bus);
        }
    }
    else {
        cout << "No bus" << endl;
    }
}

void all_buses(const map<string, vector<string>>& catalog) {
    if (catalog.size() > 0) {
        for (auto item : catalog) {
            cout << "Bus " << item.first << ":";
            for (auto s : item.second) {
                cout << " " << s;
            }
            cout << endl;
        }
    }
    else {
        cout << "No buses" << endl;
    }
}

int main() {
    int n, stop_count;
    cin >> n;
    string tmp, input1;
    vector<string> stops;
    map<string, vector<string>> catalog;
    for (int i = 0 ; i < n; ++i) {
        cin >> tmp;
        if (tmp == "NEW_BUS") {
            cin >> input1 >> stop_count;
            stops.resize(stop_count);
            for (int j = 0; j < stop_count; ++j) {
                cin >> stops[j];
            }
            new_bus(catalog, input1, stops);
        }
        if (tmp == "BUSES_FOR_STOP") {
            cin >> input1;
            buses_for_stop(catalog, input1, "");
        }
        if (tmp == "STOPS_FOR_BUS") {
            cin >> input1;
            stops_for_bus(catalog, input1);
        }
        if (tmp == "ALL_BUSES") {
           all_buses(catalog);
        }
    }
    return 0;
}
