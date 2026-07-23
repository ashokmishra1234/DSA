class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n  > m) return  "";
        map<char,int>  mp;
        for(auto ch:t) mp[ch]++;
        int required_cnt=n;
        int min_window_len=INT_MAX;
        int strt_i=0;
        int i=0,j=0;
        while( j < m){
            if(mp[s[j]] > 0){
                required_cnt--;
            }
            mp[s[j]]--;
            while(required_cnt==0){
                int window_size=j-i+1;
                if(window_size < min_window_len){
                    min_window_len=window_size;
                    strt_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) required_cnt++;
                i++;

            }
            j++;
        }
        if(min_window_len==INT_MAX) return "";
        return s.substr(strt_i,min_window_len);

    }
};