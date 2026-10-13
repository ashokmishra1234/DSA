class Solution {
public:
    bool isPos(vector<int> &nums,long long mid,int k){
        int cnt=0;
        long long sum=0;
        for(auto ele:nums){
            sum+=ele;
            if(sum > mid){
                cnt+=1;
                sum=ele;
            }
        }
        if(sum >0) cnt+=1;
        if(cnt > k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=*max_element(nums.begin(),nums.end());
        long long  high=accumulate(nums.begin(), nums.end(),0LL);
        int ans=0;
        while(low <= high){
            long long mid=low+(high-low)/2;
            if(isPos(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};