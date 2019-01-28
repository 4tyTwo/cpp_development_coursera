#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
	vector<string> words;
	auto begin = s.begin();
	while (begin != s.end())
	{
		if (begin != s.begin())
			++begin;
		auto end = find(begin, s.end(), ' ');
		words.push_back(string(begin, end));
		begin = end;
	}
	return words;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;
	return 0;
}
