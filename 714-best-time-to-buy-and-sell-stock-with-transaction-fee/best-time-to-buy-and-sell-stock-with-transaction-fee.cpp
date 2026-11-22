class Solution {
public:
    int solve(int ind,int fee,int buy, vector<int> &prices,vector<vector<int>> &dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans1=0,ans2=0;
        if(buy){
            ans1=max(ans1,-prices[ind] +solve(ind+1,fee,!buy,prices,dp));
            ans2=max(ans2,solve(ind+1,fee,buy,prices,dp));
            return dp[ind][buy]=max(ans1,ans2);
        }
        ans1=prices[ind]-fee + solve(ind+1,fee,!buy,prices,dp);
        ans2=solve(ind+1,fee,buy,prices,dp);
        return dp[ind][buy]=max(ans1,ans2);

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,fee,1,prices,dp);
    }
};