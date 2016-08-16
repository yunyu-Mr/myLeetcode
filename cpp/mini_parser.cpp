/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        // Stack store outter nested integer.
        stack<NestedInteger *> layer;
        // Empty nestedInteger.
        NestedInteger *pNested = nullptr;
        
        // Case single integer: "324"
        if (s[0] != '[') {
            int x = atoi(s.c_str());
            NestedInteger integer(x);
            return integer;
        }
        // Otherwise, nested integer.
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == '[') {
                // Get into an inner nested, snapshot outer nested.
                if (pNested != nullptr) layer.push(pNested);
                pNested = new NestedInteger();
            }
            else if (c == ']') {
                if (layer.empty()) continue;
                // Current nested is over, get out of it and restore outter nested.
                NestedInteger *old = pNested;
                pNested = layer.top();
                pNested->add(*old);
                layer.pop();
            }
            else if (c == ' ' || c == ',') continue;    // Pass the dellimeter.
            else {
                // scan number.
                for (int j = i; j < len ;j++) 
                    if (s[j] == ',' || s[j] == ']') {
                        if (i != j+1) {  // Not empty.
                            int x = atoi(s.substr(i,j).c_str());
                            NestedInteger integer(x);
                            pNested->add (integer);
                        }
                        if (s[j] == ']') i = j-1;
                        else             i = j;
                        break;
                    } 
                    else if (s[j]==' ') continue;
            }
        }
        return *pNested;
    }
};