class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(auto ele:nums) st.insert(ele);
        int longest=1;
        for(auto ele:st){
            if(st.find(ele-1)==st.end()){
                int cnt=1;
                int x=ele;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};