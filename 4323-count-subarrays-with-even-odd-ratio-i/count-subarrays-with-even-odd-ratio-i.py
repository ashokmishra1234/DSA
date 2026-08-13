class Solution:
    def countRatioSubarrays(self, nums: list[int], a: int, b: int) -> int:
        n=len(nums)
        ans=0
        for i in range(n):
            odd_cnt,even_cnt=0,0
            for j in range(i,n):
                if nums[j]%2==1:
                    odd_cnt+=1
                else:
                    even_cnt+=1
                if odd_cnt==0:
                    continue
                else:
                    if even_cnt / odd_cnt <= a / b:
                        ans+=1
        return ans

                