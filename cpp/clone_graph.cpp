/*
 *	Clone Graph
 */

#include <iostream>
#include <vector>
#include <unordered_map>

 using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	// Record visited node, which should not be clone again.
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visitedMap;

public:
	/*
	 * Graph traversal and clone
	 *
	 * Here I use DFS
	 */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node == nullptr)
    		return node;

    	UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);

    	visitedMap[node] = newNode;
    	// cout<<"Visit "<<node->label<<endl;

    	// Visit all neighbor
        for (int i = 0; i < node->neighbors.size(); i++) {
        	// if neighbor not visited
        	UndirectedGraphNode * neighbor = node->neighbors[i];

        	// If not visited yet, which means not clone. Create a new node.
        	if (visitedMap.find(neighbor) == visitedMap.end()) { // not visited

        		UndirectedGraphNode* nextNode = cloneGraph(neighbor);

        		newNode->neighbors.push_back(nextNode);
        		
        	} else 
        	{
        		//Otherwise, point to the existed node. Check visitedMap.
        		newNode->neighbors.push_back(visitedMap[neighbor]);
        	}
        }

        return newNode;
    }
};

int main(int argc, char const *argv[])
{
	UndirectedGraphNode * node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode * node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode * node2 = new UndirectedGraphNode(2);
	node0->neighbors = {node1, node2};
	node1->neighbors = {node0,node1};
	node2->neighbors = {node0,node1,node2};

	Solution s;
	UndirectedGraphNode* tmpNode = s.cloneGraph(node0);

	return 0;
}