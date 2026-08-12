class Solution {
public:
    int get_height(int i,vector<vector<int>> &adjList){
        int ans=1;
        for(auto &nodes:adjList[i]){
            ans=max(ans,1+get_height(nodes,adjList));
        }
        return ans;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        long long ans=0;
        vector<vector<int>> adjList(n);
        for(int i=1;i<n;i++){
            adjList[parent[i]].push_back(i);
        }
        int h=get_height(0,adjList);
        cout<<h<<endl;
        queue<pair<int,int>> q;
        q.push({0,1});
        while(!q.empty()){
            auto [node,d]=q.front();
            q.pop();
            ans+=(1LL*nums[node]*(h-d+1));
            for(auto &nodes:adjList[node]){
                q.push({nodes,d+1});
            }
        }
        return ans;
    }
};