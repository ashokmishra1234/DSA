
class Solution(object):
    def combinationSum2(self, candidates, target):
        candidates.sort()
        ans = []

        def backtrack(start, target, path):
            if target == 0:
                ans.append(path[:])
                return

            for i in range(start, len(candidates)):
                candidate = candidates[i]

                if candidate > target:
                    break

                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                path.append(candidate)
                backtrack(i + 1, target - candidate, path)
                path.pop()

        backtrack(0, target, [])
        return ans
