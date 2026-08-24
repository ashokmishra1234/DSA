class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        set<pair<int,int>,greater<pair<int,int>>> st;
        int max_ele=0;
        for(int i=0;i<k;i++){
            st.insert({nums[i],i});
        }
        int i=0,j=k;
        while(j < n){
            auto [ele,ind]=*st.begin();
            ans.push_back(ele);
            st.erase({nums[i],i});
            st.insert({nums[j],j});
            i++;
            j++;
        }
        auto [ele,ind]=*st.begin();
        ans.push_back(ele);
        return ans;
    }
};