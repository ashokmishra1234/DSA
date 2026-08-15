class Solution {
public:
    bool isPos(long long in_boost,vector<int> &monsters,vector<long long> &diff){
        int n=monsters.size();
        long long curr_boost=in_boost;
        int i=0;
        while(i < n){
            int req_boost=monsters[i];
            if(curr_boost+diff[i] >= req_boost){
                curr_boost-=req_boost;
                if(curr_boost < 0) curr_boost=0;
            }else
                return false;
            i++;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> diff(n+1);
        for(auto it:boosts){
            int l=it[0];
            int r=it[1];
            int b=it[2];
            diff[l]+=b;
            diff[r+1]-=b;
        }
        for(int i=1;i<(n+1);i++){
            diff[i]+=diff[i-1];
        }
        long long  total_sum=accumulate(monsters.begin(),monsters.end(),0LL);
        long long low=0;
        long long high=total_sum;
        long long ans=0;
        while(low <= high){
            long long mid=low+(high-low)/2;
            if (isPos(mid,monsters,diff)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};