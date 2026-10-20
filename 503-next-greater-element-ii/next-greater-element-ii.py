class Solution:
    def nextGreaterElements(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [-1] * n
        st = []
        for i in range(2 * n - 1, -1, -1):
            curr = nums[i % n]
            while st and st[-1] <= curr:
                st.pop()
            if i < n:
                if st:
                    ans[i] = st[-1]
            st.append(curr)
            
        return ans