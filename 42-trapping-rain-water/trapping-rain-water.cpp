class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1,lmax=0,rmax=0;
        int ans=0;
        while(l < r){
            if(arr[l] < arr[r]){
                if(arr[l] < lmax){
                    ans+=(lmax-arr[l]);
                   
                }else{
                    lmax=max(lmax,arr[l]);
                }
                l+=1;
            }else{
                if(arr[r] < rmax){
                    ans+=(rmax-arr[r]);
                }else rmax=max(rmax,arr[r]);
                r--;
            }
        }
        return ans;
    }
};