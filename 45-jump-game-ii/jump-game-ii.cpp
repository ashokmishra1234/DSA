class Solution {
public:
    // int solve(int ind,int n,vector<int> &nums,vector<int> &dp){
    //     if(ind >= n) return 1e5;
    //     if(ind==n-1) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     int steps=1e9;
    //     for(int i=1;i<=nums[ind];i++){
    //         steps=min(steps,1+solve(i+ind,n,nums,dp));
    //     }
    //     return dp[ind]=steps;
    // }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxReachable=0;
        int steps=0;
        int i=0;
        while(maxReachable < n-1 ){
            int temp=maxReachable;
            while(i <= maxReachable){
                temp=max(temp,i+nums[i]);
                i++;
            }
            maxReachable=temp;
            steps++;
        }
        return steps;
    }
};