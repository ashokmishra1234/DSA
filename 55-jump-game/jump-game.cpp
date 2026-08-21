class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_pos=0;
        for(int i=0;i<n;i++){
            if( i <= max_pos) max_pos=max(max_pos,nums[i]+i);
        }
        if(max_pos >= n-1) return true;
        return false;
    }
};