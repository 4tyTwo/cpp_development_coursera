#pragma once
#include <algorithm>
#include <sstream>
#include <vector>

#include "phone_number.h"

vector<string> parse_number(const string& s)
{
	stringstream ss(s);
	vector<string> res(3);
	string token;
	int first_delim = s.find('-', 0);
	int second_delim = s.find('-', first_delim + 1);
	res[0] = s.substr(0, first_delim);
	res[1] = s.substr(first_delim + 1, second_delim - first_delim - 1);
	res[2] = s.substr(second_delim + 1);
	return res;
}

PhoneNumber::PhoneNumber(const string& international_number)
{
	if (international_number[0] != '+' || count(international_number.begin(), international_number.end(), '-') < 2)
		throw invalid_argument("Wrong format");
	size_t offset = 1;
	auto tokens = parse_number(international_number.substr(1));
	if (count(tokens.begin(), tokens.end(), "") > 0)
		throw invalid_argument("Code can't be empty");
	country_code_ = tokens[0];
	city_code_ = tokens[1];
	local_number_ = tokens[2];
}

string PhoneNumber::GetCountryCode() const { return country_code_; };
string PhoneNumber::GetCityCode() const { return city_code_; };
string PhoneNumber::GetLocalNumber() const { return local_number_; };
string PhoneNumber::GetInternationalNumber() const { return "+" + country_code_ + "-" + city_code_ + "-" + local_number_; };