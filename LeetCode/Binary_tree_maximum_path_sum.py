

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        self.maximum = float('-inf')
        
        def dfs(root):
            if root is None:
                return 0
            left_max = max(0,dfs(root.left))
            right_max = max(0,dfs(root.right))
            self.maximum = max(self.maximum,left_max+right_max+root.val)
            return max(left_max,right_max)+root.val
        
        dfs(root)
        return self.maximum
        
        