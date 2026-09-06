# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans=[]
        if not root:
            return ans
        q=deque()
        q.append(root)

        flag=True
        while q:
            temp=[]
            q_size=len(q)
            while q_size:
                node=q.popleft()
                temp.append(node.val)
                if node.left:
                    q.append(node.left)
                if  node.right:
                    q.append(node.right)
                q_size-=1
            if not flag:
                temp.reverse()
            ans.append(temp)
            flag=not flag
        return ans
