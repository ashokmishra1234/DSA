class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(auto ch:tasks){
            freq[ch]+=1;
        }
        priority_queue<int> pq;
        for(auto [ch,cnt]:freq) pq.push(cnt);
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            int cnt=n+1;
            while(cnt && !pq.empty()){
                int val=pq.top();
                pq.pop();
                temp.push_back(val);
                cnt--;
            }
            for(auto ele:temp){
                if(ele - 1 > 0) pq.push(ele-1);
            }
            if(pq.size() > 0) ans+=(n+1);
            else ans+=(temp.size());
        }
        return ans;
    }
};