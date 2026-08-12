class Solution {
public:
    int solve(int i, int j, int n, int m, string &s, string &p){
        if(j>=m){
            if(i==n) return true;
            return false;
        }
        bool first_ch_matched=false;
        if( i < n && (s[i]==p[j] || p[j]=='.')) first_ch_matched=true;
        if(j+1 < m && p[j+1]=='*'){
            bool  take= first_ch_matched && solve(i+1,j,n,m,s,p);
            bool not_take=solve(i,j+2,n,m,s,p);
            return take || not_take;
        }
        return first_ch_matched && solve(i+1,j+1,n,m,s,p);
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(0,0,n,m,s,p);
    }
};