class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n=len(nums)
        mp={}
        ans=0
        cumm_sum=0
        mp[0]=mp.get(0,0)+1
        for ind in range(n):
            cumm_sum+=nums[ind]
            temp=cumm_sum-goal
            if temp in mp:
                ans+=mp[temp]
            mp[cumm_sum]=mp.get(cumm_sum,0)+1
        return ans