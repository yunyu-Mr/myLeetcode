// Trie Tree Node
struct TrieNode {
	int val;                        // Value
    vector<TrieNode*> children;     // Children
    
	TrieNode(int val = 0): val(val), children(128, nullptr) {}  // Constructor (ASCII: 128)
};

class MapSum {
    TrieNode *root;     // Trie tree root.
    
    // DFS: visit trie tree.
    void dfs(TrieNode *root, int &sum) {
        if (root == nullptr) return;
        
        sum += root->val;
        
        for (auto child : root->children)
            if (child != nullptr)
                dfs(child, sum);
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *curr = root;
        for (char c : key) {
            if (curr->children[c] == nullptr)
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->val = val;  // Set value of the key.
    }
    
    int sum(string prefix) {
        TrieNode *curr = root;
        // Skip the prefix.
        for (char c : prefix)
            if (curr->children[c] != nullptr)
                curr = curr->children[c];
            else return 0;
        // Count the sum by DFS.
        int s = 0;
        dfs(curr, s);
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */