class Solution {
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> l_min(n,0),r_min(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) l_min[i]=-1;
            else l_min[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) r_min[i]=n;
            else r_min[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int ld=i-l_min[i];
            int rd=r_min[i]-i;
            ans=(ans+ 1LL*arr[i]*(ld*rd)%MOD)%MOD; 
        }
        return ans;
    }
};