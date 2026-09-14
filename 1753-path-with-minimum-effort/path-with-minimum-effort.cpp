class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int rows=heights.size();
        int cols=heights[0].size();\
        vector<vector<int>> dist(rows,vector<int>(cols,1e9));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        dist[0][0]=0;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto [effort,r,c]=pq.top();
            pq.pop();
            // if(effort > dist[r][c]) continue;
            if(r==rows-1 && c ==cols-1) return effort;
            for(auto [dr,dc]:dir){
                int newr=r+dr;
                int newc=c+dc;
                if(newr >= 0 && newr < rows && newc >= 0 && newc <cols ){
                    int neweffort=max(effort,abs(heights[r][c]-heights[newr][newc]));
                    if(neweffort < dist[newr][newc]){
                        dist[newr][newc]=neweffort;
                        pq.push({neweffort,newr,newc});
                    }
                }
            }
        }
        return 0;
    }
};