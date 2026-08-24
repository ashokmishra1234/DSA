class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=arrivalTime.size();
        int max_light=*max_element(lights.begin(),lights.end());
        int wt_time=0;
        for(int i=0;i<n;i++){
            int r=arrivalTime[i]%period;
            if(r >= max_light){
                wt_time=max(wt_time,period-r);
            }
        }
        return wt_time;
    }
};