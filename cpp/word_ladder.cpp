#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
private:
	bool isNextWord(const string& word1, const string& word2) {
		if (word1.length() != word2.length()) {
			return false;
		}
		int cnt = 0;
		for (int i =0; i < word1.length(); ++i) {
			if (word1[i] != word2[i])
				cnt++;
			if (cnt > 1)
				return false;
		}
		if (cnt == 0)
			return false;
		return true;
	}

public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	if (beginWord.length() == 0)
    		return 0;

    	// Queue pair: first: word; second: count
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while (!q.empty()) 
        {
        	// Get the front element
        	pair<string, int> qfront = q.front();
        	q.pop();

        	// Check if it is near endWord
        	if (isNextWord(qfront.first, endWord))
        		return qfront.second + 1;

        	// Iterate the wordList and find the NextWord( one char diff)
        	for (auto pWord = wordList.begin(); pWord != wordList.end(); ) 
        	{
        		if (isNextWord(*pWord, qfront.first)) 
        		{
        			q.push(make_pair(*pWord, qfront.second + 1));
        			wordList.erase(pWord++);
        		}
        		else {
        			pWord++;
        		}

        	}
        }

        return 0;
    }
};


int main(int argc, char const *argv[])
{
	unordered_set<string> wordList = {"hot","dot","lot","log","dog"};
	for (auto it = wordList.begin(); it != wordList.end(); it++) {
		cout<<*it<<"\t";
	}
	cout<<endl;

	Solution s;
	cout<<s.ladderLength("hit", "cog", wordList);
	return 0;
}
