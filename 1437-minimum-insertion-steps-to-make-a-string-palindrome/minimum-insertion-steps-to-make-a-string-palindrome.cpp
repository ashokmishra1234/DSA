class Solution {
public:
    int solve(int left, int right,vector<vector<int>> &dp, string &s){
        if(left > right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        if(s[left]==s[right]) {
            return dp[left][right]=solve(left+1,right-1,dp,s);
        }
        return dp[left][right]=1+min(solve(left+1,right,dp,s), solve(left,right-1,dp,s));  
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,dp,s);
        
    }
};