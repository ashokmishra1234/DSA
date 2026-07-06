class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(ind==prices.size()-1){
            if(buy) return 0;
            return prices[ind];
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            int take=-prices[ind]+solve(ind+1,!buy, prices,dp);
            int not_take=solve(ind+1,buy,prices,dp);
            return dp[ind][buy]=max(take,not_take);
        }
        int sell=prices[ind]+solve(ind+2,!buy,prices,dp);
        int not_sell=solve(ind+1,buy,prices,dp);
        return dp[ind][buy]=max(sell,not_sell);
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};