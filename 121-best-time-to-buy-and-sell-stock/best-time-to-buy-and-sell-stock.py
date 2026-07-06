class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        next_greater=[0]*n
        next_greater[n-1]=-1
        for i in range(n-2,-1,-1):
            next_greater[i]=max(prices[i+1],next_greater[i+1])
        ans=0
        for i in range(0,n,1):
            ans=max(ans,next_greater[i]-prices[i])
        return ans