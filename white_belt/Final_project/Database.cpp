#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

const vector<string> allowed_commands = { "Add", "Find", "Del", "Print" };

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

vector<int> parseDate(string date)
{
	if (count(date.begin() + 1, date.end(), '-') != 2) {
		return {};
	}
	int delim1 = date.find('-', 1); // to omit potential negative sign
	int delim2 = date.find('-', delim1 + 1);
	try {
		return { stoi(date.substr(0, delim1)), stoi(date.substr(delim1 + 1, delim2)), stoi(date.substr(delim2 + 1)) };
	}
	catch (exception& e) {
		return {};
	}
}

void validate_date(int month, int day)
{
	if (month < 1 || month > 12) {
		throw runtime_error("Month value is invalid: " + to_string(month));
	}
	if (day < 1 || day > 31) {
		throw runtime_error("Day value is invalid: " + to_string(day));
	}
}


class Date {
public:
	Date()
	{
		_day = _month = 1;
		_year = 1970;
	}

	Date(const string& raw_date)
	{
		vector<int> date_vector;
		date_vector = parseDate(raw_date);
		if (date_vector.empty()) {
			throw runtime_error("Wrong date format: " + raw_date);
		}
		try {
			validate_date(date_vector[1], date_vector[2]);
		}
		catch (runtime_error& e) {
			throw;
		}
		_year  = date_vector[0];
		_month = date_vector[1];
		_day   = date_vector[2];
	}

	Date(Day d, Month m, Year y)
	{
		_day = d.value;
		_month = m.value;
		_year = y.value;
	}

	bool operator< (const Date& comp) const
	{
		if (_year != comp._year)
			return _year < comp._year;
		else
			if (_month != comp._month)
				return _month < comp._month;
			else
				return _day < comp._day;
	}

	inline int day()   const { return _day; };
	inline int month() const { return _month; };
	inline int year()  const { return _year; };

private:
	int _day, _month, _year;
};

ostream& operator<< (ostream& out, const Date& date)
{
	return  out << setfill('0') << setw(4) << date.year() << "-" << setw(2) << date.month() << "-" << setw(2) << date.day();
}


class Database {
public:
	void add(const Date& date, const string& ev)
	{
		db[date].insert(ev);
	}

	string erase(const Date& date)
	{
		int deleted_events_count = 0;
		if (contains(date)) {
			deleted_events_count = db[date].size();
			db.erase(date);
		}
		return "Deleted " + to_string(deleted_events_count) + " events";
	}

	string erase(const Date& date, const string& ev)
	{
		if (contains(date)) {
			if (db[date].count(ev) > 0) {
				db[date].erase(ev);
				return "Deleted successfully";
			}
		}
		return "Event not found";
	}

	vector<string> find(const Date& date)
	{
		if (contains(date)) {
			return { db[date].begin(), db[date].end() };
		}
		return {};
	}

	void print(ostream& out)
	{
		for (auto item : db) {
			for (auto ev : item.second) {
				out << item.first << " " << ev << endl;
			}
		}
	}

private:

	bool contains(const Date& date)
	{
		return db.count(date) > 0;
	}

	map<Date, set<string>> db;
};

vector<string> parseCommand(string line)
{
	stringstream ss(line);
	vector<string> res;
	string token;
	while (getline(ss, token, ' '))
		res.push_back(token);
	return res;
}

bool validate_command_name(const string& command)
{
	return count(allowed_commands.begin(), allowed_commands.end(), command) > 0;
}

int main() {
	Database db;
	string command;
	while (getline(cin, command)) {
		vector<string> command_tokens = parseCommand(command);
		if (command_tokens.size() > 0) {
			if (validate_command_name(command_tokens[0])) {
				if (command_tokens[0] == "Print")
					db.print(cout);
				if (command_tokens[0] == "Add") {
					Date date;
					try {
						date = Date(command_tokens[1]);
						db.add(date, command_tokens[2]);
					}
					catch (runtime_error& e) {
						cout << e.what() << endl;
					}
				}
				if (command_tokens[0] == "Del") {
					Date date;
					try {
						date = Date(command_tokens[1]);
						if (command_tokens.size() == 2)
							cout << db.erase(date) << endl;
						else
							cout << db.erase(date, command_tokens[2]) << endl;
					}
					catch (runtime_error& e) {
						cout << e.what() << endl;
					}
				}
				if (command_tokens[0] == "Find") {
					Date date;
					try {
						date = Date(command_tokens[1]);
						for (auto ev : db.find(date))
							cout << ev << endl;
					}
					catch (runtime_error& e) {
						cout << e.what() << endl;
					}
				}
			}
			else
				cout << "Unknown command: " << command_tokens[0] << endl;
		}
	}
	return 0;
}
