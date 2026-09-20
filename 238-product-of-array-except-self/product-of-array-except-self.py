class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n=len(nums)
        pref_prod,suff_prod=[1]*n,[1]*n
        for ind, ele in  enumerate(nums):
            if(ind==0):
                pref_prod[ind]=ele
                suff_prod[n-ind-1]=nums[n-ind-1]
            else:
                pref_prod[ind]=pref_prod[ind-1]*ele
                suff_prod[n-ind-1]=suff_prod[n-ind]*nums[n-ind-1]
        ans=[]
        for ind,ele in enumerate(nums):
            prev,suff=1,1
            if ind -1 >= 0:
                prev=pref_prod[ind-1]
            if ind+1 < n:
                suff=suff_prod[ind+1]
            ans.append(prev*suff)
        return ans