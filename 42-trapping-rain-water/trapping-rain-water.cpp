class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left_max(n,0),right_max(n,0);
        int curr_max=0;
        //right_max
        for(int i=n-1;i>=0;i--){
            if(curr_max > height[i])right_max[i]=curr_max;
            curr_max=max(curr_max,height[i]);
        }
        curr_max=0;
        //left max
        for(int i=0;i<n;i++){
            if(curr_max > height[i]) left_max[i]=curr_max;
            curr_max=max(curr_max,height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int lh=left_max[i];
            int rh=right_max[i];
            int ah=min(lh,rh);
            if(ah) ans+=(ah-height[i]);
        }
        return ans;
    }
};