class Solution {
public:
    int solve(int ind, int buy, int cap,vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap==0) return 0;
        if(ind==prices.size()-1){
            if(buy) return 0;
            return prices[ind];
        }
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            int take=-prices[ind]+solve(ind+1,!buy,cap, prices,dp);
            int not_take=solve(ind+1,buy,cap,prices,dp);
            return dp[ind][buy][cap]=max(take,not_take);
        }
        int sell=prices[ind]+solve(ind+1,!buy,cap-1,prices,dp);
        int not_sell=solve(ind+1,buy,cap,prices,dp);
        return dp[ind][buy][cap]=max(sell,not_sell);
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};