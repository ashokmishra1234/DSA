class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> t(n,vector<bool> (n,false));
        vector<int> dp(n,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++) t[i][i]=true;
        for(int L=2;L<=n;L++){
            for(int i=0;i<=n-L;i++){
                int j=i+L-1;
                if(L==2){
                    if(s[i]==s[j]) t[i][j]=true;
                    else t[i][j]=false;
                }else{
                    if(s[i]==s[j] && t[i+1][j-1]) t[i][j] =true;
                    else t[i][j]=false;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(t[0][i]){
                dp[i]=0;
                continue;
            }
            for(int k=0;k<i;k++){
                if(t[k+1][i]){
                    if(1+dp[k] < dp[i]){
                        dp[i]=1+dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};