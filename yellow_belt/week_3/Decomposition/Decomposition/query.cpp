#include "query.h"

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