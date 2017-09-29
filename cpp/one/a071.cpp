class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 1, j = 1, n = path.length();
        if (n == 0) return "";
        
        while (i < n) {
            // Find a dir seperator "/".
            while (j < n && path[j] != '/') j++;
            // Dir name
            const string& dir = path.substr(i, j-i);
            //
            if (dir == "..") {
                // Back to upper dir.
                // If no upper, stay "/".
                if (!s.empty()) s.pop();
            }
            else if (dir != "." && dir != "") { // skip current dir.
                s.push(dir);
            }
            i = ++j;  // next
        }
        
        // Construct simplify path.
        string smp = "";
        vector<string> tmp;
        while (!s.empty()) {
            tmp.push_back(s.top());
            s.pop();
        }
        reverse(tmp.begin(), tmp.end());  // reverse
        for (const auto& str : tmp)
            smp += "/" + str;
        return smp == "" ? "/" : smp;
    }
};