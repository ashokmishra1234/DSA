class Solution {
public:
    int solve(int ind_s, int indt,string &s, string &t, vector<vector<int>> &dp){
        if(indt==0) return 1;
        if(ind_s == 0) return 0;
        if(dp[ind_s][indt]!=-1) return dp[ind_s][indt];
        if(s[ind_s-1]==t[indt-1]){
            return dp[ind_s][indt]=solve(ind_s-1,indt-1,s,t,dp) + solve(ind_s-1,indt,s,t,dp);
        }
        else {
            return dp[ind_s][indt]=solve(ind_s-1,indt,s,t,dp);
        }
    }
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t,dp);
    }
};