class Solution {
public:
    int solve(int ind,int n, int tag,vector<int> &prices,vector<vector<int>> &dp){
        if(ind==n-1){
            if(tag==0) return 0;
            return prices[ind];
        }
        if(dp[ind][tag]!=-1) return dp[ind][tag];
        if(tag==0){
            int take=solve(ind+1,n,!tag,prices,dp)-prices[ind];
            int not_take=solve(ind+1,n,tag,prices,dp);
            return dp[ind][tag]=max(take,not_take);
        }else  return dp[ind][tag]=max(prices[ind],solve(ind+1,n,tag,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,n,0,prices,dp);
    }
};