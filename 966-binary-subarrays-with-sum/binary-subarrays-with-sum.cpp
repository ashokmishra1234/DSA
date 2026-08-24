class Solution {
public:
    int solve(vector<int> &nums, int target){
        if(target < 0) return 0;
        long long  cum_sum=0;
        int ans=0; 
        int n=nums.size();
        int l=0,r=0;
        while( r < n){
            cum_sum+=nums[r];
            while(cum_sum > target && l < n){
                cum_sum-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans1=solve(nums,goal);
        int ans2=solve(nums,goal-1);
        return ans1-ans2;
    }
};