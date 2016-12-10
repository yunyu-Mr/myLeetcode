#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 128;

class Solution {
public:
	string frequencySort(string s) {
		// Loopup table.
		vector<pair<char, int> > table(SIZE, make_pair(0, 0));
		for (int i = 0; i < table.size(); i++)
			table[i].first += i;
		// Count frequency.
		for (char c: s) {
			table[c].second++;
		}
		// Sort, using lambda expression.
		std::sort(table.begin(), table.end(),
			[](pair<char, int> a, pair<char, int> b) {
				return b.second < a.second;
			}
		);
		// Build the sorted string.
		std::string ordered = "";
		for (int i = 0; i < table.size(); i++) {
			if (table[i].second == 0) break;
			
			ordered += std::string(table[i].second, table[i].first);
		}
		return ordered;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.frequencySort("tree") << endl;
	cout << s.frequencySort("Aabb") << endl;
	return 0;
}