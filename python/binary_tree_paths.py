# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        if root is None:
            return []
        self.allPaths = []
        
        self.travel(root, "")
            
        return self.allPaths
    
    def travel(self, root, path):
        # Is leaf.
        if root.left is None and root.right is None:
            self.allPaths.append(path + str(root.val))
            return
        if root.left is not None:
            self.travel(root.left, path + str(root.val) + "->")
        if root.right is not None:
            self.travel(root.right, path + str(root.val) + "->")