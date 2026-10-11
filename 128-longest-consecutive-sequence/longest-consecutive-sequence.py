class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        n=len(nums)
        st=set(nums)
        ans_cnt=0
        for ele in st:
            if ele -1 in st:
                continue
            else:
                cnt=1
                while ele+1 in st:
                    cnt+=1
                    ele+=1
                ans_cnt=max(ans_cnt,cnt)
        return ans_cnt