class Solution {
public:
    struct cmp{
        bool operator()(auto &a, auto &b){
            if(a.first==b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    string reorganizeString(string s) {
        int n=s.size();
        sort(s.begin(),s.end());
        int ind=(n+1)/2;
        if(s[0]==s[ind]) return "";
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        for(auto &[ch,freq]:mp) pq.push({freq,ch});
        string ans="";
        while(pq.size() > 1){
            auto [freq1,ch1]=pq.top();
            pq.pop();
            auto [freq2,ch2]=pq.top();
            pq.pop();
            ans.push_back(ch1);
            freq1--;
            ans.push_back(ch2);
            freq2--;
            if(freq1 > 0) pq.push({freq1,ch1});
            if(freq2 > 0) pq.push({freq2,ch2});

            
        }
        
        while(!pq.empty()){
            auto [freq,ch]=pq.top();
            if(freq > 1) return "";
            pq.pop();
            ans.push_back(ch);
        }
        return ans;
    }
};