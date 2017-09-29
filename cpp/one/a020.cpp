class Solution {
public:
    bool isPair(char a, char b) {
        switch (a) {
            case '(': return b == ')';
            case '[': return b == ']';
            case '{': return b == '}';
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (char c : s)
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (!st.empty() && isPair(st.top(), c)) {
                st.pop();
            } else
                return false;
        return st.empty();
    }
};