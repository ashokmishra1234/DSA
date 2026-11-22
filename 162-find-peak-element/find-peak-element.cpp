class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int  n=nums.size();
        if(n==1 || nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int l=0,r=n-1;
        while( l < r){
            int mid=l+(r-l)/2;
            if(mid+1 < n && nums[mid+1] >  nums[mid]) l=mid+1;
            else r=mid;
        }
        return l;
    }
};