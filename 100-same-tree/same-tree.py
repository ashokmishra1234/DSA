# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode | None, q: TreeNode | None) -> bool:
        if not p and not q:
            return True
        if (p and not q) or (not p and q):
            return False
        if p.val!=q.val:
            return False
        ans1=self.isSameTree(p.left,q.left)
        ans2=self.isSameTree(p.right,q.right)
        ans =ans1 and ans2
        return ans        