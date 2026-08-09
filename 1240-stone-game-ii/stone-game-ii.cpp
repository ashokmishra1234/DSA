class Solution {
public:
    int t[2][101][101];
    int solve(int person, int i, int M,vector<int> &piles){
        int n=piles.size();
        if(i >= n) return 0;
        if(t[person][i][M]!=-1) return t[person][i][M];
        int store=0;
        int result=person==1?INT_MIN:INT_MAX;

        for(int x=1;x <= min(2*M,n-i);x++){
            if(person==1){
                store+=piles[i+x-1];
                result=max(result,store+solve(!person,i+x,max(M,x),piles));
            }
            else{
                result=min(result,solve(!person,i+x,max(M,x),piles));
            }
        }
        return t[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n=piles.size();
        return solve(1,0,1,piles);
    }
};