class Solution:
    def maxDepth(self, s: str) -> int:
        opencnt=0
        ans=float('-inf')
        for char in s:
            if char=='(':
                opencnt+=1
                ans=max(ans,opencnt)
            elif char==')':
                opencnt-=1
        if ans==float('-inf'):
            return 0
        return ans

