class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int max_ans=INT_MIN;
        while ( l < r){
            int min_h=min(height[l],height[r]);
            int width=r-l;
            max_ans=max(max_ans,min_h*width);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return max_ans;

    }
};