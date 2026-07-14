class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        string to_remove="";
        for(int i=0;i<n;i++){
            char ch=num[i];
            while ( !st.empty() && ch < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=(st.top());
            st.pop();
        }
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        while(ans.size() > 1 && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};