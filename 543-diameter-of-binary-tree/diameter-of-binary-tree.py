# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_diameter=0
        def get_dia(root):
            nonlocal max_diameter
            if not root:
                return 0
            left_dia=get_dia(root.left)
            right_dia=get_dia(root.right)
            max_diameter=max(max_diameter,left_dia+right_dia)
            return 1+max(left_dia,right_dia)
        get_dia(root)
        return max_diameter