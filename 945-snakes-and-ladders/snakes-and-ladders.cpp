class Solution {
public:
    int n;
    pair<int,int> get_coord(int val){
        int tr=(val-1)/n;
        int br=n-1-tr;
        int col=(val-1)%n;
        if((n%2==1 && br%2==1 ) || (n%2==0 && br%2==0)) col=n-1-col;
        return make_pair(br,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        queue<int> q;
        q.push(1);
        vis[n-1][0]=1;
        int steps=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                int val=q.front();
                q.pop();
                if(val==n*n) return steps;
                for(int k=1;k<=6;k++){
                    int new_val=val+k;
                    if(new_val > n*n) break;
                    pair<int,int> coord=get_coord(new_val);
                    int r=coord.first;
                    int c=coord.second;
                    if(vis[r][c]) continue;
                    vis[r][c]=true;
                    if(board[r][c]==-1) q.push(new_val);
                    else q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};