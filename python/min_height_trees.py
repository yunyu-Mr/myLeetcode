class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        # Adjacency list
        adj = [set() for i in xrange(n)]
        # Degree list
        degree = [0 for i in xrange(n)]
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)
        for i in xrange(n):
            degree[i] = len(adj[i])
            
        # Remove nodes level by level (the nodes' degree equal to 1 should be removed)
        remain = set([i for i in xrange(n)])
        while len(remain) > 2:
            rm_record = []
            
            for v in remain:
                if degree[v] == 1:
                    # Record nodes that should be removed
                    rm_record.append(v)
                    
            for v in rm_record:
                for u in adj[v]:
                    degree[u] -= 1
                remain.remove(v)

        return list(remain)
                    
class Solution2(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n <= 2:
            return [i for i in xrange(n)]
        # Adjacency list
        adj = [set() for i in xrange(n)]
        for i, j in edges:
            adj[i].add(j)
            adj[j].add(i)
            
        p1 = self.bfs(adj, 0, 1)
        p2 = self.bfs(adj, p1[-1], 2)
        if len(p2) % 2:
            return p2[len(p2)/2:len(p2)/2+1]
        return p2[len(p2)/2-1:len(p2)/2+1]
            
    def bfs(self, adj, u, num_pass):
        """
        :type adj: List(Set(int))
        :type u: int
        :rtype: List[int]
        """
        # queue for bfs.
        q = [ u ]
        # because the graph has no cycle, we can control visit by using one list.
        visited = set()
        # depth
        d = [0 for i in xrange(len(adj))]
        # parent
        p = [-1 for i in xrange(len(adj))]
        
        while len(q) > 0:
            u = q.pop(0)
            visited.add(u)
            for v in adj[u]:
                if v not in visited:
                    d[v] = d[u] + 1
                    p[v] = u
                    q.append(v)
                    
        if num_pass == 1:
            return [u]
            
        path = []
        while u != -1:
            path.append(u)
            u = p[u]
        return path
                    
if __name__ == '__main__':
    s = Solution2()
    print s.findMinHeightTrees(6, [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]])