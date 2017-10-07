# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum, start=False):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if root is None:
            return 0
        
        count = 0
        if root.val == sum:
            count += 1
            
        count += self.pathSum(root.left, sum - root.val, start=True)
        count += self.pathSum(root.right, sum - root.val, start=True)
        
        # 若当前节点已加入path，则接下来不可跳过节点。
        if not start:
            count += self.pathSum(root.left, sum)
            count += self.pathSum(root.right, sum)
        return count