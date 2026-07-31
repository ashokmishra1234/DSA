class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        int n=word.size();
        for(int i=0;i<n;i++) mp[word[i]-'a']++;

        sort(mp.rbegin(),mp.rend());
        for(int i=0;i<26;i++) cout<<mp[i]<<endl;
        int ans=0;
        int mul_factor=1;
        int cnt=0;
        for(auto freq:mp){
            if(cnt / 8 ==0) ans+=(freq * 1);
            else if(cnt / 8 ==1) ans+=(freq*2);
            else if(cnt / 8 ==2)ans+=(freq*3);
            else ans+=(freq*4);
            cnt++;
           
        }
        return ans;
    }
};