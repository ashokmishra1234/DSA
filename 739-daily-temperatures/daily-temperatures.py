class Solution:
    def dailyTemperatures(self, nums: list[int]) -> list[int]:
        n=len(nums)
        ans=[0]*n
        ans[n-1]=0
        stack=[]
        stack.append(n-1)
        for i in range(n-2,-1,-1):
            while len(stack) > 0 and  nums[stack[-1]] <= nums[i]:
                stack.pop()
            if len(stack)==0:
                ans[i]=0
            else:
                ans[i]=stack[-1]-i
            stack.append(i)
        return ans