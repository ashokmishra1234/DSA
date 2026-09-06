# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    max_sum=-float('inf')
    def solve(self,root):
        if not root:
            return 0
        ls=self.solve(root.left)
        rs=self.solve(root.right)
        self.max_sum=max(self.max_sum,max(max(root.val+ls,root.val+rs),root.val+ls+rs))
        self.max_sum=max(self.max_sum,root.val)
        return max(root.val,max(root.val+ls,root.val+rs))
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.max_sum
        