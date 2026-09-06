# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    max_height=0
    def solve(self,root):
        if not root:
            return 0
        lh=self.solve(root.left)
        rh=self.solve(root.right)
        self.max_height=max(self.max_height,lh+rh)
        return 1+max(lh,rh)
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.max_height