class Solution {
public:
    vector<vector<string>> result;
    bool isPal(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
    void solve(int ind, string& s, vector<string>& temp) {
        if (ind == s.size()) {
            result.push_back(temp);
            return;
        }
        if (ind > s.size())
            return;
        for (int i = ind; i < s.size(); i++) {
            if (isPal(ind, i, s)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // vector<vector<bool>> dp(n,vector<bool> (n,false));
        // for(int i=0;i<n;i++) dp[i][i]=true;
        // for(int len=2;len <= n;len++){
        //     for(int i=0;i<n && i+len-1 < n;i++){
        //         int j=i+len-1;
        //         if(len==2){
        //             dp[i][j]=(s[i]==s[j]);
        //         }
        //         else{
        //             dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
        //         }
        //     }
        // }
        vector<string> temp;
        solve(0, s, temp);
        return result;
    }
};