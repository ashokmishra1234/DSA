class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int fac=1;
        for(int i=0;i<n;i++){
            if(nums[i]%k==0 && nums[i]/k==fac) fac++;
        }
        return fac*k;
    }
};