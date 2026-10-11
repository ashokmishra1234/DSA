class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }
    
private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int l = 0, h = nums.size() - 1;
        int bound = -1;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    h = mid - 1; // Search left for the first occurrence
                } else {
                    l = mid + 1; // Search right for the last occurrence
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return bound;
    }
};