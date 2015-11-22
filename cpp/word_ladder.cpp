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
    	if (beginWord.length() == 1)
    		return 1;

    	int len = 1;

        queue<string> q;
        q.push(beginWord);
        q.push("");
        while (!q.empty()) {
        	string nextWord = q.front();
        	// cout<<"nextWord: "<<nextWord<<endl;
        	if (nextWord == "")
        		break;
        	q.pop();

        	// 
        	if (isNextWord(nextWord, endWord))
        		return ++len;

        	//
        	auto pWord = wordList.begin();
        	while (pWord != wordList.end())
        	{
        		if (isNextWord(nextWord, *pWord))
        		{
        			// cout<<*pWord<<"\t";
        			q.push(*pWord);
        			wordList.erase(pWord++);
        		}
        		else {
        			pWord++;
        		}
        	}

        	if (q.front() == ""){
        		q.push("");
        		q.pop();
        		len++;
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
