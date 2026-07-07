class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> len(n,1);
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size() < b.size();
            });
        int ans=0;
        for(int i=0;i<n;i++){
            string str=words[i];
            int temp=0;
            for(int k=0;k<str.size();k++){
                string s=str;
                str.erase(k,1);
                
                for(int j=0;j<i;j++){
                    if(words[j]==str){
                        temp=max(temp,1+len[j]);
                    }
                }
                str=s;
            }
            len[i]=max(len[i],temp);
            ans=max(ans,len[i]);
        }
        return ans;
    }
};