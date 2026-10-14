#include <vector>

class Solution {
private:
    void findCombinationsBrute(int index, int target, std::vector<int>& candidates, 
                               std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index == candidates.size()) {
            return;
        }

        // Option 1: Pick the current candidate (can pick the same index again)
        current.push_back(candidates[index]);
        findCombinationsBrute(index, target - candidates[index], candidates, current, result);
        current.pop_back();
        findCombinationsBrute(index + 1, target, candidates, current, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        findCombinationsBrute(0, target, candidates, current, result);
        return result;
    }
};