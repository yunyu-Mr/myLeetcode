# Course Schedule I
# Using Depth First Search

WHITE = 0
GRAY = 1
BLACK = 2

class Graph(object):
    def __init__(self, n):
        self.V = []
        self.Adj = [[] for i in xrange(n)]

class Vertex(object):
    def __init__(self, label):
        self.label = label
        self.parent = None
        self.d = 0
        self.f = 0
        self.color = WHITE
        
        
class Solution(object):
    def dfs(self, graph):
        self.time = 0
        for u in graph.V:
            if u.color == WHITE:
                if self.dfs_visit(graph, u) == False:
                    return False
        return True
                
    def dfs_visit(self, graph, u):
        u.color = GRAY
        for v in graph.Adj[u.label]:
            # If adjacent vertex is GRAY, a loop is form.
            if v.color == GRAY:
                return False
            if v.color == WHITE:
                if self.dfs_visit(graph, v) == False:
                    return False
        u.color = BLACK
        return True
        
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        # Turn into adjacency list.
        graph = Graph(numCourses)
        graph.V = [Vertex(i) for i in xrange(numCourses)]
        for edge in prerequisites:
            graph.Adj[edge[0]].append(graph.V[edge[1]])
        # DFS.
        return self.dfs(graph)
        
if __name__ == '__main__':
    s = Solution()
    print s.canFinish(2, [[1,0],[0,1]])
    