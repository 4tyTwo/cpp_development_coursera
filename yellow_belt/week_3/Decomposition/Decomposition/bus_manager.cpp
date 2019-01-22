#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops)
{
	buses_to_stops[bus] = stops;
	for (const string& stop : stops)
		stops_to_buses[stop].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
{
	if (stops_to_buses.count(stop) == 0)
		return { false, {} };
	return { true, stops_to_buses.at(stop) };
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const
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

AllBusesResponse BusManager::GetAllBuses() const
{
	return { buses_to_stops };
}