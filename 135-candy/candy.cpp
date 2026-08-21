class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> allocate(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1])   allocate[i]=max(allocate[i],allocate[i-1]+1);
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]) allocate[i]=max(allocate[i],allocate[i+1]+1);  
        }
        int ans=accumulate(allocate.begin(),allocate.end(),0);
        return ans;
    }
};