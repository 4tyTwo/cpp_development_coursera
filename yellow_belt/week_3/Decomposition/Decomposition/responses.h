#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct InterchangeStops
{
	string stop;
	vector<string> interchanges;
};

struct BusesForStopResponse
{
	bool success;
	vector<string> data;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse
{
	bool success;
	vector<InterchangeStops> data;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse
{
	map<string, vector<string>> data;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);