class Solution:
    def solve(self,ind,rem_amnt,coins,dp):
        if rem_amnt==0:
            return 0
        if ind < 0:
            return 1e9
        if dp[ind][rem_amnt]!= -1:
            return dp[ind][rem_amnt]
        take=1e9
        if coins[ind] <= rem_amnt:
            take=1+self.solve(ind,rem_amnt-coins[ind],coins,dp)
        not_take=self.solve(ind-1,rem_amnt,coins,dp)
        dp[ind][rem_amnt]=min(take,not_take)
        return dp[ind][rem_amnt]
    def coinChange(self, coins: List[int], amount: int) -> int:
        n=len(coins)
        dp=[[-1]* (amount+1) for _ in range(n)]
        ans= self.solve(n-1,amount,coins,dp)
        if ans==1e9:
            return -1
        return ans