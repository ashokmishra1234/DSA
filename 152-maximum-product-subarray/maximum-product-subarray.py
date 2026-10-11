class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        n=len(nums)
        max_prod=float('-inf')
        prod=1
        zero=False
        for i in range(n):
            if nums[i]==0:
                zero=True
                prod=1
                continue
            prod*=nums[i]
            max_prod=max(max_prod,prod)
        prod=1
        for i in range(n-1,-1,-1):
            if nums[i]==0:
                prod=1
                continue
            prod*=nums[i]
            max_prod=max(max_prod,prod)
        if zero:
            if max_prod < 0:
                return 0
        return max_prod