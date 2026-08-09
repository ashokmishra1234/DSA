class Solution {
public:
    // vector<int> ans;
    // void solve(int i,int j,int n,int m,int cnt, string &word1, string &word2,vector<int> &temp){
    //     if( (i<=n && j==m) || j==m){
    //         if(ans.size()==0){
    //             ans=temp;
    //         }
    //         else if(temp < ans) ans=temp;
    //         return;
    //     }
    //     if(i==n) return;
    //     if(word1[i]==word2[j]){
    //         temp.push_back(i);
    //         solve(i+1,j+1,n,m,cnt ,word1,word2,temp);
    //         temp.pop_back();
    //     }else{
    //         if(cnt > 0){
    //             temp.push_back(i);
    //             solve(i+1,j+1,n,m,cnt-1,word1,word2,temp);
    //             temp.pop_back();
    //         }
    //         solve(i+1,j,n,m,cnt,word1,word2,temp);
    //     }
    //     return;
    // }
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(m > n) return  {};
        vector<int> right_match(n,0);
        int match=0;
        int i=n-1,j=m-1;
        while(i >= 0){
            if(j >= 0 && word1[i]==word2[j]){
                match++;
                j--;
            }
            right_match[i]=match;
            i--;
        }
        vector<int> seq;
        i=0,j=0;
        bool can_change=true;
        while( i< n && j < m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if (can_change && (i+1 < n && right_match[i+1]>=m-j-1)){
                seq.push_back(i);
                j++;
                can_change=false;
            }
            i++;
        }
        if(seq.size()!=m) return {};
        return seq;
    }
};