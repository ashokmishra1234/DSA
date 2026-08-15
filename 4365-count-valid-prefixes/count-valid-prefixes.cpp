class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int one_cnt=0,zero_cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero_cnt++;
            else one_cnt++;
            if(abs(one_cnt - zero_cnt) < 2) ans++;
        }
        return ans;
    }
};