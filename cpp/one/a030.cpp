#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> result;

    	int N = words.size();		// word num
    	if (N == 0) 
    		return result;
    	int k = words[0].length();  // word length
    	if (s.length() < k)
    	    return result;
    	
    	// Hash table
    	unordered_map<string, int> cntMap;
    	for (const auto& word : words)
    		++cntMap[word];

    	for (int p = 0; p < k; p++) {  // iterate k times.
    		unordered_map<string, queue<int> > posMap;
	    	for (auto& word : cntMap)
	    		posMap[word.first] = queue<int>();

    		int i = p, j = p;  // two pointers

    		// two pointer searching.
    		while(i <= s.length() - N * k && j <= s.length() - k) {
    		    const string& word = s.substr(j, k);
    		    // Not in table
    		    if (cntMap.find(word) == cntMap.end()) {
    		    	i = j = j + k;
    		    	continue;
    		    }

    		    // In table
    		    auto& q = posMap[word];
    		    q.push(j);
    		    if (q.size() > cntMap[word]) {  //dup
    		    	int pos = q.front();
    		    	q.pop();
    		    	// shrink
    		    	if (pos >= i)
    		    		i = pos + k;
    		    }
    		    // move next
    		    j += k;
    		    if (j - i == N * k)
    		    	result.push_back(i);
    		}
    	}

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	string s = "barfoofoobarthefoobarman";
	vector<string> words = {"foo", "bar", "the"};
	vector<int> res = sol.findSubstring(s, words); 
	for (int i : res)
		cout << i << endl;

	cout << endl;
	s = "xbarfoofoothefoobarman";
	words = {"foo", "bar", "the", "foo"};
	res = sol.findSubstring(s, words); 
	for (int i : res)
		cout << i << endl;

	cout << endl;
	s = "wordgoodgoodgoodbestword";
	words = {"word", "good", "good", "best"};
	res = sol.findSubstring(s, words); 
	for (int i : res)
		cout << i << endl;
	return 0;
}