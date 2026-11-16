class Solution {
public:
    string solve(string s){
        int sum=0;
        for(char ch:s){
            sum+=ch-'0';
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        int n=s.size();
        string ans=s;
        while(ans.size() > k){
            string temp="";
            int ind=0;
            while(ind + k <ans.size()){
                string curr=ans.substr(ind,k);
                temp+=solve(curr);
                ind+=k;
            }
            if(ind < ans.size()){
                string curr=ans.substr(ind,ans.size()-ind);
                temp+=solve(curr);
            }
            ans=temp;
        }
        return ans;
    }
};