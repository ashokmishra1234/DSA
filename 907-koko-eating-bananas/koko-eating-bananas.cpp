class Solution {
public:
    bool isPos(int mid,int h,vector<int> &piles){
        long long  hr=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0) hr+=(piles[i]/mid);
            else hr+=(piles[i]/mid+1);
        }
        if(hr <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(n > h) return -1;
        sort(piles.begin(),piles.end());
        int high=piles[n-1];
        int low=1;
        int ans=1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(isPos(mid,h,piles)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};