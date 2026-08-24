class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp1,mp2;
        int l=0,r=0;
        int ans_k=0;
        while(  r < n){
            mp1[nums[r]]+=1;
            while(mp1.size() > k){
                mp1[nums[l]]--;
                if(mp1[nums[l]] ==0) mp1.erase(nums[l]);
                l++;
            }
            ans_k+=(r-l+1);
            r++;
        }
        l=0,r=0;
        int ans_l=0;
        while(  r < n){
            mp2[nums[r]]+=1;
            while(mp2.size() > (k-1) ){
                mp2[nums[l]]--;
                if(mp2[nums[l]] ==0) mp2.erase(nums[l]);
                l++;
            }
            ans_l+=(r-l+1);
            r++;
        }
        return (ans_k - ans_l);
    }
};