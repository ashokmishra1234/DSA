class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        n=len(heights)
        nse=[n]*n
        pse=[-1]*n
        st=[]
        for i,h in enumerate(heights):
            while st and heights[st[-1]] >= h:
                st.pop()
            if st:
                pse[i]=st[-1]
            st.append(i)
        while st:
            st.pop()
        for i in range(n-1,-1,-1):
            h=heights[i]
            while st and heights[st[-1]] >= h:
                st.pop()
            if st:
                nse[i]=st[-1]
            st.append(i)
        ans=0
        for i in range(n):
            width=(i-pse[i]) + (nse[i]-i-1)
            curr_ans=heights[i]*width
            ans=max(ans,curr_ans)
        return ans
