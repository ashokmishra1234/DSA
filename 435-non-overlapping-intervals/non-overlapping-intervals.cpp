class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int n=intervals.size();
       sort(intervals.begin(),intervals.end());
       int prev_strt=intervals[0][0];
       int prev_end=intervals[0][1];
       int i=1;
       int ans=0;
       while( i < n){
        int curr_strt=intervals[i][0];
        int curr_end=intervals[i][1];
        if(curr_strt < prev_end){
            prev_end=min(prev_end,curr_end);
            ans++;
        }else{
            prev_strt=curr_strt;
            prev_end=curr_end;
        }
        i++;
       } 
       return ans;
    }
};