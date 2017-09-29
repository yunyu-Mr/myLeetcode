class Solution {
private:
    unordered_map<string, vector<string>> strMap;
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;  // Words Dict
        for (auto word : wordDict)
            wordSet.insert(word);
        
        return wordBreak(s, wordSet);
    }
    
    vector<string> wordBreak(const string& s, const unordered_set<string>& wordDict) {
        if (strMap.count(s)) 
            return strMap[s];  // Already break the same string.
        
        int N = s.length();
        vector<string> results;
        
        if (wordDict.count(s))    // if the whole word is already in dict
            results.push_back(s);
        
        for (int i = 1; i < N; i++)
        {
            const string& sub = s.substr(0, i);
            if (wordDict.count(sub))
                for (const string& ss: wordBreak(s.substr(i,N), wordDict))  // Recursive
                    results.push_back(sub + " " + ss);      // concat to new results.
        }
        this->strMap[s] = results;  // Remember this break for future same string.
        return results;
    }
};