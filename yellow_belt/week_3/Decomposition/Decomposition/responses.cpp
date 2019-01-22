#include "responses.h"

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