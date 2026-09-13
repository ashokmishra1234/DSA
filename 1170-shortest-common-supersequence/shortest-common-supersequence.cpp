class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string str="";
        int i=n,j=m;
        while( i > 0 && j > 0){
            if(str1[i-1]==str2[j-1]){
                str+=str1[i-1];
                i--,j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    str+=str2[j-1];
                    j--;
                }
                else{
                    str+=str1[i-1];
                    i--;
                }
            }
        }
        while( i > 0){
            str+=str1[i-1];
            i--;
        }
        while( j > 0){
            str+=str2[j-1];
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};