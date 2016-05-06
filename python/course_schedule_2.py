# Course Schedule 2
# Topological Sort.

# Color:
WHITE = 0   # Not visit
GRAY  = 1   # Visited
BLACK = 2   # Finished

class Graph(object):
    def __init__(self, n):
        # Vertex set:
        self.V = [Vertex(i) for i in xrange(n)]
        # Adjacency list:
        self.Adj = [set() for i in xrange(n)]
        
class Vertex(object):
    def __init__(self, label):
        self.label = label
        self.color = WHITE
        

# Solution.
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        if numCourses == 1:
            return [0]
        # Init graph.
        graph = Graph(numCourses)
        for i, j in prerequisites:
            graph.Adj[i].add(graph.V[j])
            
        self.order = list()
        
        # DFS:
        for u in graph.V:
            if u.color == WHITE:
                if not self.dfs_visit(graph, u):
                    return []
                
        return self.order
                
                
    def dfs_visit(self, graph, u):
         """
         :type graph: Graph
         :type u: Vertex
         """
         u.color = GRAY
         
         for v in graph.Adj[u.label]:
             # Has been visited, which mean there is cycle.
             if v.color == GRAY:
                 return False
             # Not been visited yet, visite it.
             if v.color == WHITE:
                if not self.dfs_visit(graph, v):
                    return False
                
         u.color = BLACK
         # Once it finish, add to the ordered list.
         self.order.append(u.label)
         return True
         
if __name__ == '__main__':
    s = Solution()
    print s.findOrder(4, [[1,0],[2,0],[3,1],[3,2]])