class Solution:
    def solve(self,k:int,nums:List[int]):
        n=len(nums)
        l,r=0,0
        mp={}
        ans=0
        while r < n:
            mp[nums[r]]=mp.get(nums[r],0)+1
            while len(mp) > k:
                mp[nums[l]]-=1
                if mp[nums[l]]==0:
                    del mp[(nums[l])]
                l+=1
            ans+=(r-l+1)
            r+=1
        return ans
                


    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        n=len(nums)
        mp={}
        l,r=0,0
        ans=0
        # seen=set()
        # while r < n:
        #     mp[nums[r]]=mp.get(nums[r],0)+1
        #     seen.insert(nums[r])
        #     if len(seen) > k:
        #         mp[nums[l]]-=1
        #         if mp[nums[l]]==0:
        #             mp.delete(nums[l])
        #             seen.remove(nums[l]);
        #         l+=1
        #     if len(seen)==k:
        #         ans+=1
        #     r+=1
        kminus=self.solve(k-1,nums)
        kth=self.solve(k,nums)
        ans=kth-kminus
        return ans
                
