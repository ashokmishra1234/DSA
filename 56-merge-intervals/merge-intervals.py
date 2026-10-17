class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort()
        n=len(intervals)
        ans=[]
        curr_st=intervals[0][0]
        curr_end=intervals[0][1]
        for i in range(1,n):
            if intervals[i][0] <= curr_end:
                curr_st=min(curr_st,intervals[i][0])
                curr_end=max(curr_end,intervals[i][1])
            else:
                ans.append([curr_st,curr_end])
                curr_st=intervals[i][0]
                curr_end=intervals[i][1]
        ans.append([curr_st,curr_end])
        return ans