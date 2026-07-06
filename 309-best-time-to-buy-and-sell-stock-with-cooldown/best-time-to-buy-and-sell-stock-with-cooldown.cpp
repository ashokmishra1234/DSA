class Solution {
public:
    // int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     if(ind >= prices.size()) return 0;
    //     if(ind==prices.size()-1){
    //         if(buy) return 0;
    //         return prices[ind];
    //     }
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     if(buy){
    //         int take=-prices[ind]+solve(ind+1,!buy, prices,dp);
    //         int not_take=solve(ind+1,buy,prices,dp);
    //         return dp[ind][buy]=max(take,not_take);
    //     }
    //     int sell=prices[ind]+solve(ind+2,!buy,prices,dp);
    //     int not_sell=solve(ind+1,buy,prices,dp);
    //     return dp[ind][buy]=max(sell,not_sell);
        
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return solve(0,1,prices,dp);
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n-1][1]=0;
        dp[n-1][0]=prices[n-1];
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    int take=-prices[ind]+dp[ind+1][!buy];
                    int not_take=dp[ind+1][buy];
                    dp[ind][buy]=max(take,not_take);
                }else{
                    if(ind==n-1) continue;
                    int sell=prices[ind]+dp[ind+2][!buy];
                    int not_sell=dp[ind+1][buy];
                    dp[ind][buy]=max(sell,not_sell);
                }
            }
        }
        return dp[0][1];
    }
};