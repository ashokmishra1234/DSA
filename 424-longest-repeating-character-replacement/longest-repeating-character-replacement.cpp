class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<int,int> mp;
        int l=0,r=0;
        int max_freq=0;
        int ans=0;
        while( r < n){
            mp[s[r]-'A']++;
            max_freq=max(max_freq,mp[s[r]-'A']);
            int new_freq=-1;
            while(((r-l+1) - max_freq) > k){
                mp[s[l]-'A']--;
                for(auto [ele,freq]:mp) new_freq=max(new_freq,freq);
                l++;
                max_freq=new_freq;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};