class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<int> temp(1e5+2,0),pref(1e5+2,0);
        for(int i=0;i<n;i++){
            temp[difficulty[i]]=max(temp[difficulty[i]],profit[i]);
        }
        int max_pro=temp[0];
        pref[0]=temp[0];
        for(int i=1;i<(1e5+1);i++){
            max_pro=max(max_pro,temp[i]);
            pref[i]=max_pro;
        }
        int  ans=0;
        for(int i=0;i<worker.size();i++){
            ans+=pref[worker[i]];
        }
        return ans;
    }
};