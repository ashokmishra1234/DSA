#include<bits/stdc++.h>
class Solution {
public:
    int solve(int i,int k,int n, vector<int>&arr,vector<int> &dp){
        if(i  >= n) return 0;
        if(i==n-1) return arr[n-1];
        if(dp[i]!=-1) return dp[i];
        int ans=-1e9;
        int maxi=-1;
        for(int l=1;l<=min(k,n-i);l++){
            maxi=max(maxi,arr[i+l-1]);
            int curr_ans=1LL*maxi*l+solve(i+l,k,n,arr,dp);
            ans=max(ans,curr_ans);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,k,n,arr,dp);
    }
};