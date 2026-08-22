class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int m=newInterval.size();
        sort(newInterval.begin(),newInterval.end());
        vector<vector<int>> ans;
        int prev_end=-1,prev_strt=-1;
        int i=0,j=0;
        while(i < n && j < m){
            int curr_strt=intervals[i][0];
            int curr_end=intervals[i][1];
            if(prev_strt==-1){
                prev_strt=curr_strt;
                prev_end=curr_end;
            }
            else{
                prev_end=max(prev_end,curr_end);
            }
            int newint_strt=newInterval[0];
            int newint_end=newInterval[1];
            if ( newint_end < prev_strt){
                ans.push_back({newint_strt,newint_end});
                j+=2;
            }
            else if(newint_strt <= prev_end){
                prev_strt=min(prev_strt,newint_strt);
                prev_end=max(prev_end,newint_end);
                j+=2;
            }
            else{
                ans.push_back({prev_strt,prev_end});
                prev_strt=-1;
                prev_end=-1;
            }
            i++;
        }
        while( i < n){
            int curr_strt=intervals[i][0];
            int curr_end=intervals[i][1];
            if(prev_strt==-1){
                prev_strt=curr_strt;
                prev_end=curr_end;
            }
            else if(curr_strt > prev_end){
                ans.push_back({prev_strt,prev_end});
                prev_strt=curr_strt;
                prev_end=curr_end;
            }
            else{
                prev_strt=min(prev_strt,curr_strt);
                prev_end=max(prev_end,curr_end);
            }
            i++;
        }
        if( prev_strt !=-1)ans.push_back({prev_strt,prev_end});
        if( j < 2){
            ans.push_back({newInterval[0],newInterval[1]});
        }
        
        return ans;
    }
};