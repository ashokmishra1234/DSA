class Solution {
public:
    int solve(int ind, int prevInd, vector<int> &nums,vector<vector<int>> &dp){
        if(ind >= nums.size()) return 0;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        int take=0;
        if( prevInd==-1 || nums[ind] > nums[prevInd]){
            take=1+solve(ind+1,ind,nums,dp);
        }
        int not_take=solve(ind+1,prevInd, nums,dp);
        return dp[ind][prevInd+1]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(0,-1,nums,dp);
        
    }
};