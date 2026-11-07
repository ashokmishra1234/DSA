class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        ans = []

        def backtrack(start_idx, current_sum, temp):
            if current_sum == target:
                ans.append(temp.copy())
                return
            if current_sum > target:
                return
            for i in range(start_idx, len(candidates)):
                # 1. Choose: add the number
                temp.append(candidates[i])
                backtrack(i, current_sum + candidates[i], temp)
                temp.pop()

        backtrack(0, 0, [])
        return ans