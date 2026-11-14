
class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:

        n = len(nums)

        prefix = [0] * n

        prefix[0] = nums[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        ans = float('inf')

        for i in range(n):
            for length in range(l, r + 1):

                j = i + length - 1

                if j >= n:
                    break

                if i == 0:
                    curr_sum = prefix[j]
                else:
                    curr_sum = prefix[j] - prefix[i - 1]

                if curr_sum > 0:
                    ans = min(ans, curr_sum)

        return ans if ans != float('inf') else -1
