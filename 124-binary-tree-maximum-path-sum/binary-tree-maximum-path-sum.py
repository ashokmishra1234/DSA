class Solution:
    def maxPathSum(self, root: TreeNode | None) -> int:

        ans = float('-inf')

        def max_sum(root):
            nonlocal ans

            if not root:
                return 0

            left_sum = max(0, max_sum(root.left))
            right_sum = max(0, max_sum(root.right))
            ans = max(ans, root.val + left_sum + right_sum)
            return root.val + max(left_sum, right_sum)

        max_sum(root)
        return ans
