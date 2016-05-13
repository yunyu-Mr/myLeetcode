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
            
        # Remove leaf nodes level by level
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
                    
                    
                    
if __name__ == '__main__':
    s = Solution()
    print s.findMinHeightTrees(6, [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]])