class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int> destroyed(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] > 0){
                if(arr[i] > -1*arr[st.top()]){
                    destroyed[st.top()]=1;
                    st.pop();
                }else if(arr[i] < -1*arr[st.top()]){
                    destroyed[i]=1;
                    break;
                }else{
                    destroyed[i]=1;
                    destroyed[st.top()]=1;
                    st.pop();
                    break;
                }
            }
            if(arr[i] < 0) st.push(i);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!destroyed[i]) ans.push_back(arr[i]);
        }
        return ans;
    }
};