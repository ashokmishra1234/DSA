class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum=sum(nums)
        if totalSum % 2:
            return False
        Sum=int(totalSum//2)
        n=len(nums)
        dp=[[False for _ in range(Sum+1)] for _ in range(n+1)]
        for i in range(n+1):
            dp[i][0]=True
        for i in range(n-1,-1,-1):
            for j in range(1,Sum+1):
                take,not_take=False,False
                if nums[i] <= j:
                    take=dp[i+1][j-nums[i]]
                not_take=dp[i+1][j]
                dp[i][j]=take or not_take
        return dp[0][Sum]