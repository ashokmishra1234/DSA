class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:intervals){
            int st=it[0];
            int end=it[1];
            pq.push({st,end});

        }
        int prev_end=INT_MIN;
        int ans=0;
        while (pq.size() > 0){
            auto [st,end]=pq.top();
            pq.pop();
            if (st < prev_end){
                prev_end=min(prev_end,end);
                ans+=1;
            }else{
                prev_end=end;
            }

        }
        return ans;

    }
};