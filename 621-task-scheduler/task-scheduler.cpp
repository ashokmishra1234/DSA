class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        vector<int> freq(26,0);
        for(int i=0;i<size;i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]  > 0){
                pq.push(freq[i]);
            } 
        }
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    int x=pq.top();
                    pq.pop();
                    temp.push_back(x-1);
                }
            }
            for(int i=0;i<temp.size();i++){
                    if(temp[i] > 0)pq.push(temp[i]);
            }
            if(pq.size()==0) ans+=temp.size();
            else ans+=(n+1);
        }
        return ans;
    }
};