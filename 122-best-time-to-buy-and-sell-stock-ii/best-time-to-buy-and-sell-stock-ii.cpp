class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
        if(n==1) return 0;
        int ans=0;
        int prev_min=price[0];
        for(int i=1;i<n;i++){
            if(price[i] < prev_min) {
                prev_min=min(prev_min,price[i]);
                continue;
            }else{
                ans+=price[i]-prev_min;
                prev_min=price[i];
            }  
        }
        return ans;
    }
};