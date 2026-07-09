class Solution {
public:
    int solve(int i, int j, vector<int> &cuts,vector<vector<int>> &dp){
        if(i==j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i+1;k < j;k++){
            ans=min(ans,cuts[j]-cuts[i] +solve(i,k,cuts,dp)+solve(k,j,cuts,dp));
        }
        return dp[i][j]=ans==1e9?0:ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int size=cuts.size();
        vector<vector<int>> dp(size,vector<int>(size,-1));
        return solve(0,size-1,cuts,dp);
    }
};