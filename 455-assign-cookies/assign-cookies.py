class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:
        g.sort()
        s.sort()
        n,m=len(g),len(s)
        i,j=0,0
        ans_cnt=0
        while i < n and j < m:
            if s[j] >= g[i]:
                i+=1
                ans_cnt+=1
            j+=1
        return ans_cnt