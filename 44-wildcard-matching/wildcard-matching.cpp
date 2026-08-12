class Solution {
public:
    int solve(int i, int j, int n, int m, string &s, string &p, vector<vector<int>> &dp){
        if(j==m){
            if(i==n) return true;
            return false;
        }
        if(i==n){
            // Remaining pattern must contain only '*'
            for(int k = j; k < m; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool first_ch_matched=false;
        if( i < n && s[i]==p[j] || p[j]=='?') first_ch_matched=true;
        if(j < m && p[j]=='*'){
            bool take=solve(i+1,j,n,m,s,p,dp);
            bool temp=solve(i,j+1,n,m,s,p,dp);
            return dp[i][j]=(take ||temp);
        }
        return dp[i][j]=(first_ch_matched && solve(i+1,j+1,n,m,s,p,dp));
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(0,0,n,m,s,p,dp);
    }
};