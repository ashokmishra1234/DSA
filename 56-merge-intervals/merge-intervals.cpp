class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int rows=intervals.size();
        vector<vector<int>> ans;
        int prev_strt=intervals[0][0];
        int prev_end=intervals[0][1];
        for(int r=1;r < rows;r++){
            int cs=intervals[r][0];
            int ce=intervals[r][1];
            if(cs <= prev_end){
                prev_end=max(prev_end,ce);
            }else{
                ans.push_back({prev_strt,prev_end});
                prev_strt=cs;
                prev_end=ce;
            }
        }
        ans.push_back({prev_strt,prev_end});
        return ans;
    }
};