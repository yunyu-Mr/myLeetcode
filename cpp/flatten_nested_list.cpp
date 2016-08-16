/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
typedef vector<NestedInteger>::iterator nestedit;

private:
    stack<nestedit> sc;
    stack<nestedit> se;
    nestedit cur;
    nestedit end;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur = nestedList.begin();
        end = nestedList.end();
    }

    int next() {
        // Get next integer and move next.
        return (cur++)->getInteger();
    }

    bool hasNext() {
        // Reach end, restore from stack.
        while (cur == end)
            if (sc.empty()) return false;
            else {  // Current nestedList is over, back to upper layer nestedList.
                cur = sc.top(); sc.pop();
                end = se.top(); se.pop();
                cur++;
            }
        // Move to next integer.
        while (cur != end && !cur->isInteger()) {
            // Current nested is a list, save current state and get into the new list.
            sc.push(cur);
            se.push(end);
            end = cur->getList().end();
            cur = cur->getList().begin();
            
            // In case *empty* nested list, restore.
            while (cur == end)
                if (sc.empty()) return false;
                else {  // Current nestedList is over, back to upper layer nestedList.
                    cur = sc.top(); sc.pop();
                    end = se.top(); se.pop();
                    cur++;
                }
        }
        // cur != end and next is interger.
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */