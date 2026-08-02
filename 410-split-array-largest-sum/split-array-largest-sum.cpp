class Solution {
public:
    bool isPos(int mid, int k, vector<int> &nums){
        int cnt=0;
        int n=nums.size();
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(curr_sum > mid){
                curr_sum=nums[i];
                cnt++;
            }
        }
        if(curr_sum > 0) cnt++;
        if(cnt <= k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);
        int ans=0;
        while(low <= high){
            long long mid=low+(high-low)/2;
            if(isPos(mid,k,nums)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};