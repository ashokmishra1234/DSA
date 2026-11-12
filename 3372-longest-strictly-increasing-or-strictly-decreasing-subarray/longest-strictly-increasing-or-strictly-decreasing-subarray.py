class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n=len(nums)
        ans=1
        curr_len=1
        for i in range(1,n):
            if nums[i] > nums[i-1]:
                curr_len+=1
            else:
                curr_len=1
            ans=max(ans,curr_len)
        curr_len=1
        for i in range(1,n):
            if nums[i] < nums[i-1]:
                curr_len+=1
            else:
                curr_len=1
            ans=max(ans,curr_len)
        return ans
