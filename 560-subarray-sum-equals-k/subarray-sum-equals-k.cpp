class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1; 
        
        int currentSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currentSum += num;
            if (sumFreq.find(currentSum - k) != sumFreq.end()) {
                count += sumFreq[currentSum - k];
            }
            sumFreq[currentSum]++;
        }
        
        return count;
    }
};