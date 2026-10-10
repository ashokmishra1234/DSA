class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        n=len(nums)
        i,j=0,0
        while i <  n and j < n:
            while  i < n and nums[i]!=0:
                i+=1
            while j < n and (nums[j]==0 or j < i):
                j+=1
            if i < n and j < n:
                nums[i],nums[j]=nums[j],nums[i]
        return
        