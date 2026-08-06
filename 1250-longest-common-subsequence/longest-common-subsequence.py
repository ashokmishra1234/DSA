class Solution:
    def solve(self,i,j,n,m,text1,text2,dp):
        if i >= n or j >= m:
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        if text1[i]==text2[j]:
            dp[i][j]=1+self.solve(i+1,j+1,n,m,text1,text2,dp)
            return dp[i][j]
        dp[i][j]=max(self.solve(i+1,j,n,m,text1,text2,dp),self.solve(i,j+1,n,m,text1,text2,dp));
        return dp[i][j]
        
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n=len(text1)
        m=len(text2)
        dp=[[-1]*m for _ in range(n)]
        return self.solve(0,0,n,m,text1,text2,dp)