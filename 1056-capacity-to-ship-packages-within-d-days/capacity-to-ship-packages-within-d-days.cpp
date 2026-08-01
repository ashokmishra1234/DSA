class Solution {
public:
    int solve(int max_cap,vector<int> &weights){
        int n=weights.size();
        int day=0,curr_cap=0;
        for(int i=0;i<n;i++){
            curr_cap+=weights[i];
            if(curr_cap==max_cap){
                curr_cap=0;
                day++;
            }else if(curr_cap > max_cap){
                curr_cap=weights[i];
                day++;
            }
        }
        if(curr_cap > 0) day++;
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=0;
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(solve(mid,weights) <= days){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};