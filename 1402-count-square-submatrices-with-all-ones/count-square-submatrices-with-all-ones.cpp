class Solution {
public:
    int solve(int i,int j,int rows, int cols, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i >= rows || j >= cols || !matrix[i][j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,rows,cols,matrix,dp);
        int diag=solve(i+1,j+1,rows,cols,matrix,dp);
        int down=solve(i+1,j,rows,cols,matrix,dp);
        return dp[i][j]=1+min({right,diag,down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols,-1));
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans+=solve(i,j,rows,cols,matrix,dp);
            }
        }
        return ans;
    }
};