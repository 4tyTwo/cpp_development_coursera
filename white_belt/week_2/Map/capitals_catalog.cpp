#include <iostream>
#include <string>
#include <map>

using namespace std;

void change_capital(map<string, string>& catalog, string country, string capital) {
    if (catalog.count(country) > 0) {
        // exists
        string old_capital =  catalog[country];
        if (old_capital == capital) {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else {
            catalog[country] = capital;
            cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
        }
    }
    else {
        catalog[country] = capital;
        cout << "Introduce new country " << country << " with capital " << capital << endl;
    }
}

void rename(map<string, string>& catalog, string old_country_name, string country_name) {
    if (catalog.count(old_country_name) == 0 || old_country_name == country_name || catalog.count(country_name)  > 0) {
        // error
        cout << "Incorrect rename, skip" << endl;
    }
    else {
        string capital = catalog[old_country_name];
        cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << country_name << endl;
        catalog.erase(old_country_name);
        catalog[country_name] = capital;
    }
}

void about(const map<string, string>& catalog, string country) {
    if (catalog.count(country) > 0) {
        cout << "Country " << country << " has capital " << catalog.find(country)->second << endl; // rewrite
    }
    else {
        cout << "Country " << country << " doesn't exist" << endl;
    }
}

void dump(const map<string, string>& catalog) {
    if (catalog.size() == 0) {
        cout << "There are no countries in the world" << endl;
    }
    else {
        for (auto item : catalog) {
            cout << item.first << "/" << item.second << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, day;
    cin >> n;
    string tmp, input1, input2;
    map<string, string> catalog;
    for (int i = 0 ; i < n; ++i) {
        cin >> tmp;
        if (tmp == "CHANGE_CAPITAL") {
            cin >> input1 >> input2;
            change_capital(catalog, input1, input2);
        }
        if (tmp == "RENAME") {
            cin >> input1 >> input2;
            rename(catalog, input1, input2);
        }
        if (tmp == "ABOUT") {
            cin >> input1;
            about(catalog, input1);
        }
        if (tmp == "DUMP") {
            dump(catalog);
        }
    }
    return 0;
}
