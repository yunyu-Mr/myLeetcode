# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        _ = self.cumGreaterSum(root, 0)
        return root
        
    def cumGreaterSum(self, root, greaterSum):
        """
        后序遍历
        """
        if root is None:
            return greaterSum
        
        greaterSum = self.cumGreaterSum(root.right, greaterSum)
        root.val += greaterSum
        greaterSum = root.val
        
        return self.cumGreaterSum(root.left, greaterSum)