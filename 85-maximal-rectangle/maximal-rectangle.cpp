class Solution {
public:
    int solve(vector<int>& heights) {
        int n=heights.size();
        vector<int> left_small(n),right_small(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) right_small[i]=n;
            else right_small[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) left_small[i]=-1;
            else left_small[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int curr_area=heights[i]*(i-left_small[i] + -1 + right_small[i]-i);
            ans=max(ans,curr_area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> height(rows,vector<int>(cols,0));
        for(int j=0;j<cols;j++) height[0][j]=matrix[0][j]-'0';
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1') height[i][j]=1+height[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<rows;i++){
            ans=max(ans,solve(height[i]));
        }
        return ans;

    }
};