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
    
    void escape() {
        // cur reach end but stack is not empty.
        while (cur == end && !sc.empty()) {
            // Restore from stack.
            cur = sc.top(); sc.pop();
            end = se.top(); se.pop();
            // Move to next.
            cur++;
        }
    }
    
    void moveNext() {
        // Point to first integer.
        while (cur != end && !cur->isInteger()) {
            // Snapshot.
            sc.push(cur);
            se.push(end);
            end = cur->getList().end();
            cur = cur->getList().begin();
            // Escape in case empty list.
            escape();
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur = nestedList.begin();
        end = nestedList.end();
        // Point to first integer.
        if (cur != end) moveNext();
    }

    int next() {
        // Get integer.
        int result = cur->getInteger();
        // Move next.
        cur++;
        // Escape current list if reached end yet.
        escape();
        // Move to next integer.
        moveNext();
        
        return result;
    }

    bool hasNext() {
        if (cur == end && sc.empty())  return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */