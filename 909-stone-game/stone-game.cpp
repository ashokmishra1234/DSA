class Solution {
public:
    int pl1_score=0,pl2_score=0;
    int solve(int i,int j, int move, vector<int> &piles){
        if( i < j){
            if(pl1_score >= pl2_score) return true;
            return false;
        }
        if(move %2){
            pl1_score+=piles[i];
            bool res1=solve(i+1,j,move+1,piles);
            pl1_score-=piles[i];
            pl1_score+=piles[j];
            bool res2=solve(i,j-1,move+1,piles);
            pl1_score-=piles[j];
            return (res1 || res2);
        }
        pl2_score+=piles[i];
        bool res1=solve(i+1,j,move+1,piles);
        pl2_score-=piles[i];
        pl2_score+=piles[j];
        bool res2=solve(i,j-1,move+1,piles);
        pl2_score-=piles[j];
        return (res1 && res2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        return solve(0,n-1,1,piles);
    }
};