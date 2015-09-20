# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
        	return [None]
        if n == 1:
        	root = TreeNode(1)
        	return [root]

        btree = list()
        # zero tree
        btree.append([[None] for x in range(n+1)])
        # One node tree
        btree.append(list())
        for i in xrange(1,n+1):
        	root = TreeNode(i)
        	btree[1].append([root])

        for intval in xrange(1,n):

        	btree.append(list())

        	for i in xrange(0, n-intval):
        		print i, i + intval
        		j = i + intval
        		btree[intval+1].append(list())
        		btree[intval+1][i] = list()

        		for k in xrange(i,j+1):
        			for ltree in btree[k-i][i]:
        				# print j-k, k+1
        				for rtree in btree[j-k][k+1]:
        					root = TreeNode(k+1)
        					root.left = ltree
        					root.right = rtree
        					btree[intval+1][i].append(root)
        return btree[-1][0]

    def dfs(self, i, j):
        """
        i: start point, j: stop point
        """
        if i > j:
            return [None]
        if i == j:
            root = TreeNode(i)
            return [root]
        u_list = list()
        for k in xrange(i,j+1):
            ltree = self.dfs(i, k-1)
            rtree = self.dfs(k+1, j)
            for l in xrange(len(ltree)):
                for r in xrange(len(rtree)):
                    # print l, r
                    root = TreeNode(k)
                    root.left = ltree[l]
                    root.right = rtree[r]
                    u_list.append(root)
        # print u_list
        return u_list

if __name__ == '__main__':
	s = Solution()
	print len(s.generateTrees(5))

	print "recursive: ", len( s.dfs(1,6) )