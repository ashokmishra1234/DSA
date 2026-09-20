class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums)==0:
            return 0
        seen=set()
        for ele in nums:
            seen.add(ele)
        max_ans=float('-inf')
        for ele in seen:
            if (ele-1) in seen:
                continue
            else:
                cnt=0
                while ele in seen:
                    cnt+=1
                    ele+=1
                max_ans=max(max_ans,cnt)

        return max_ans
