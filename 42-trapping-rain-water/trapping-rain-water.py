class Solution:
    def trap(self, height: list[int]) -> int:
        n=len(height)
        pge=[0]*n
        nge=[0]*n
        ans=0
        for i in range(n-2,-1,-1):
            nge[i]=max(nge[i+1],height[i+1])
        for i in range(1,n):
            pge[i]=max(pge[i-1],height[i-1])
        for i,h in enumerate(height):
            lowest_h=min(pge[i],nge[i])
            diff=lowest_h-h
            if diff > 0:
                ans+=diff
        return ans
        