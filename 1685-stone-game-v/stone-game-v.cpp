class Solution {
public:
    int solve(int i,int j, vector<int> &nums, vector<int> &pref_sum, vector<vector<int>> &dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pivot=-1,total_sum=0;
        for(int k=i;k<=j;k++) total_sum+=nums[k];
        int diff=1e8;
        int curr_sum=0;
        int score=0;
        int ans=-1;
        for(int k=i;k<j;k++){
            pivot=k;
            int l_sum=pref_sum[pivot]- (i > 0?pref_sum[i-1]:0),r_sum=pref_sum[j]-pref_sum[pivot];
            if(r_sum > l_sum) score=l_sum + solve(i,pivot,nums,pref_sum,dp);
            else if(l_sum > r_sum) score=r_sum+ solve(pivot+1,j,nums,pref_sum,dp);
            else{
                score=l_sum+max(solve(i,pivot,nums,pref_sum,dp),solve(pivot+1,j,nums,pref_sum,dp));
            }
            ans=max(ans,score);
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> pref_sum(n,0);
        pref_sum[0]=stoneValue[0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=1;i<n;i++) pref_sum[i]=stoneValue[i]+pref_sum[i-1];
        return solve(0,n-1,stoneValue,pref_sum,dp);
    }
};