#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType
{
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query
{
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

struct InterchangeStops
{
	string stop;
	vector<string> interchanges;
};

istream& operator >> (istream& is, Query& q)
{
	string command;
	is >> command;
	if (command == "NEW_BUS")
	{
		q.type = QueryType::NewBus;
		int stop_count;
		cin >> q.bus >> stop_count;
		q.stops.resize(stop_count);
		for (auto& stop : q.stops)
			cin >> stop;
	}
	if (command == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;
		cin >> q.stop;
	}
	if (command == "STOPS_FOR_BUS")
	{
		q.type = QueryType::StopsForBus;
		cin >> q.bus;
	}
	if (command == "ALL_BUSES")
	{
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse
{
	bool success;
	vector<string> data;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
	if (!r.success)
	{
		os << "No stop";
		return os;
	}
	for (const auto& item : r.data)
		cout << item << " ";
	return os;
}

struct StopsForBusResponse
{
	bool success;
	vector<InterchangeStops> data;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
	if (!r.success)
	{
		os << "No bus";
		return os;
	}
    int i = r.data.size();
	for (const auto& item : r.data)
	{
        --i;
		os << "Stop " << item.stop << ":";
		if (item.interchanges.size() == 0)
			os << " no interchange";
		else
		{
			for (const auto& stop : item.interchanges)
				os << " " << stop;
		}
        if (i != 0)
		    os << endl;
	}
	return os;
}

struct AllBusesResponse
{
	map<string, vector<string>> data;
};

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
	if (r.data.size() == 0)
		os << "No buses";
    int i = r.data.size();
	for (const auto item : r.data)
	{
        --i;
		os << "Bus " << item.first << ":";
		for (const auto& stop : item.second)
			os << " " << stop;
		if (i != 0)
		    os << endl;
	}
	return os;
}

class BusManager
{
public:
	void AddBus(const string& bus, const vector<string>& stops)
	{
		buses_to_stops[bus] = stops;
		for (const string& stop : stops)
			stops_to_buses[stop].push_back(bus);
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const
	{
		if (stops_to_buses.count(stop) == 0)
			return { false, {} };
		return { true, stops_to_buses.at(stop) };
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const
	{
		if (buses_to_stops.count(bus) == 0)
			return { false, {} };
		vector<InterchangeStops> res;
		for (const string& stop : buses_to_stops.at(bus))
		{
			vector<string> interchanges;
			if (stops_to_buses.at(stop).size() > 1)
			{
				for (const string& other_bus : stops_to_buses.at(stop))
					if (bus != other_bus)
						interchanges.push_back(other_bus);
			}
			else
				interchanges = {};
			res.push_back({ stop, interchanges });
		}
		return { true, res };
	}

	AllBusesResponse GetAllBuses() const
	{
		return { buses_to_stops };
	}
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
