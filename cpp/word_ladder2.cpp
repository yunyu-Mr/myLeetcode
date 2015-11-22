#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Ladder
{
private:
    string word;
    int level;
    int prev;
public:
    Ladder(string word, int level, int prev):
        word(word),
        level(level),
        prev(prev)
    { }
    ~Ladder() {};
    int getLevel() {return level;}
    int getPrev()  {return prev; }
    const string& getWord() {return word; }
};

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
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
    	vector<vector<string>> vWords;
        vector<vector<Ladder>> vLadders;

        if (beginWord.length() == 0)
    		return vWords;

    	// Queue pair: first: word; second: count
        queue<Ladder> q;
        q.push(Ladder(beginWord, 0, -1));
        vLadders.push_back(vector<Ladder>() );

        //
        while (!q.empty())
        {
        	// Get the front element
        	Ladder qfront = q.front();

        	// Check if it is near endWord
        	if (isNextWord(qfront.getWord(), endWord))
        		break;
            else
                q.pop();

            //
            if (qfront.getLevel() > vLadders.size() -1) 
            {
                vector<Ladder> newLadders;
                newLadders.push_back(qfront);
                vLadders.push_back(newLadders);
        	}else 
            {
                vLadders[qfront.getLevel()].push_back(qfront);
            }

        	// Iterate the wordList and find the NextWord( one char diff)
        	for (auto pWord = wordList.begin(); pWord != wordList.end(); )
        	{
        		if (isNextWord(*pWord, qfront.getWord()))
        		{
                    Ladder newLadder(*pWord,                        // string
                                    qfront.getLevel()+1,            // level
                                    vLadders[qfront.getLevel()].size() -1 // prev
                                    );
        			q.push(newLadder);
        			wordList.erase(pWord++);
        		}
        		else {
        			pWord++;
        		}

        	}
        }

        if (q.empty())
            return vWords;
        while (!q.empty())
        {
            Ladder ladder = q.front();
            q.pop();
            if (!isNextWord(endWord, ladder.getWord()))
                continue;

            vector<string> words;
            words.push_back(endWord);
            words.push_back(ladder.getWord());

            while (ladder.getPrev() >= 0)
            {
                ladder = vLadders[ladder.getLevel()-1][ladder.getPrev()];
                words.push_back(ladder.getWord());
            }

            // 
            reverse(words.begin(), words.end());
            vWords.push_back(words);
        }
        
        for (auto row = vWords.begin(); row != vWords.end(); row++) {
            for (auto e = row->begin(); e!= row->end(); e++)
                cout<<*e<<"  ";
            cout<<endl;
        }

        return vWords;
    }
};


int main(int argc, char const *argv[])
{
	unordered_set<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
	for (auto it = wordList.begin(); it != wordList.end(); it++) {
		cout<<*it<<"\t";
	}
	cout<<endl;

	Solution s;
	s.findLadders("red", "tax", wordList);
	return 0;
}
