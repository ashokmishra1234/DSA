class Solution {
public:
    // int solve(int i,int j,int rows, int cols, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    //     if(i >= rows || j >= cols || !matrix[i][j]) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right=solve(i,j+1,rows,cols,matrix,dp);
    //     int diag=solve(i+1,j+1,rows,cols,matrix,dp);
    //     int down=solve(i+1,j,rows,cols,matrix,dp);
    //     return dp[i][j]=1+min({right,diag,down});
    // }
    int countSquares(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows+1,vector<int> (cols+1,0));
        int ans=0;
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if;
        //     }
        // }
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=0;j--){
                if(matrix[i][j]){
                    dp[i][j]=1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};