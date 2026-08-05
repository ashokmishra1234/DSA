class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            adjList[u].push_back(v);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(k);
        vis[k]=true;
        while(!q.empty()){
            int sus=q.front();
            q.pop();
            for(auto adjNode:adjList[sus]){
                if(!vis[adjNode]){
                    vis[adjNode]=true;
                    q.push(adjNode);
                }
            }
        }
        vector<int> ans;
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            if(vis[u]==false &&vis[v]==true){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};