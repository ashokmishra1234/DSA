class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n=planks.size();
        unordered_map<long long , int> mp;
        for(int i=0;i<n;i++){
            mp[planks[i]]++;
        }
        vector<pair<long long ,int>> v;
        for(auto it:mp) v.push_back({it.first,it.second});
        int m=v.size();
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int t=v[i].first+v[j].first;
                if(i==j){
                    mp[t]+=(v[i].second/2);
                }else
                    mp[t]+=min(v[i].second,v[j].second);
            }
        }
        int ans=0;
        for(auto it:mp) ans=max(ans,it.second);
        return ans;
    }
};