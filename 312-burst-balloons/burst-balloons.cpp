class Solution {
public:
     int solve(int l ,int r , vector<int> &nums, vector<vector<int>> &dp){
        if(l > r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=-1e9;
        for(int k=l;k<=r;k++){
            int steps=nums[k]*nums[l-1]*nums[r+1]+solve(l,k-1,nums,dp)+solve(k+1,r,nums,dp);
            ans=max(ans,steps);
        }
        return dp[l][r]=ans;
     }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int size=nums.size();
        vector<vector<int>> dp(size,vector<int>(size,-1));
        return solve(1,size-2,nums,dp);

    }
};