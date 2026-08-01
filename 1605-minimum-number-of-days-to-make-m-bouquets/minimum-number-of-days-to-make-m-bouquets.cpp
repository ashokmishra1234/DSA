class Solution {
public:
    int solve(int mid, int m, int k, vector<int> &bloomDay){
        int n=bloomDay.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){
                cnt++;
                if(cnt==k){
                    m--;
                    cnt=0;
                } 
            }else cnt=0;
        }
        if(m<=0) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n < (1LL*m*k)) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(low <= high){
            int mid=low+(high-low)/2;
            if( solve(mid,m,k,bloomDay)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};