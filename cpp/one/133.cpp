/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode UGNode;

class Solution {
public:
    UGNode *cloneGraph(UGNode *node) {
        unordered_map<UGNode*, UGNode*> copyTable;  // originalNode -> copyNode
        unordered_set<UGNode*> visited;             // Node that has been visited
        
        return cloneGraph(node, visited, copyTable);
    }
    
    UGNode *cloneGraph(UGNode *node, unordered_set<UGNode*> &visited, unordered_map<UGNode*, UGNode*> &copyTable) 
    {
        if (!node) return nullptr;
        
        if (visited.count(node)) return copyTable[node];    // return if visited
        
        UGNode *copyNode = new UGNode(node->label);
        copyTable[node] = copyNode;
        visited.insert(node);
        
        // DFS cloning
        for (auto neighbor : node->neighbors)
            copyNode->neighbors.push_back (cloneGraph(neighbor, visited, copyTable)); // Add neighbors

        return copyNode;
    }
};