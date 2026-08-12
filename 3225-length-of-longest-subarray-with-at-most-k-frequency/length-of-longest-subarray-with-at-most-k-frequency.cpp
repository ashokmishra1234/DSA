class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> freq;
        int ans=0;
        while(j < n){
            freq[nums[j]]++;
            if(freq[nums[j]] > k){
                ans=max(ans,j-i);
                while(i <= j && freq[nums[j]] > k){
                    freq[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};