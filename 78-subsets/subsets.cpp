
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int start, vector<int>& nums) {
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);

            backtrack(i + 1, nums);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        subset.clear();

        backtrack(0, nums);

        return ans;
    }
};
