class Solution {
public:
    int solve(int mid, vector<int> &nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0) sum+=(nums[i]/mid);
            else sum+=(nums[i]/mid + 1);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(solve(mid,nums) <= threshold){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};