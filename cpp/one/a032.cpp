class Solution {
    // example:
    // "()( ()"
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // store the index of '('
        vector<int> index(s.length(), -1);
        
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else 
            {   // ')'
                if (!st.empty()) {
                    index[i] = st.top();    // point to the index of matched '('.
                    st.pop();
                }
            }
            // 如果当前形成一段完成括号串，检查前面是否已有串。
            // 若有，则连成一起。
            if (index[i] != -1) {
                int p = index[i];
                if (p > 0 && index[p-1] != -1)
                    index[i] = index[p-1];    // 连成一串。
                // update maxLen
                maxLen = max (maxLen, i - index[i] +1);
            }
        }
        
        return maxLen;
    }
};