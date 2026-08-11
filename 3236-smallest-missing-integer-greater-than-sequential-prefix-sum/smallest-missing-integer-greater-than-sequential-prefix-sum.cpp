class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(auto &ele:nums) st.insert(ele);
        int curr_sum=nums[0],ans_sum=0;
        int l_seq=0;
        int curr_seq_len=1;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1]+1){
                break;
                if(curr_seq_len > l_seq){
                    l_seq=curr_seq_len;
                    ans_sum=curr_sum;
                    curr_sum=0;
                    curr_seq_len=0;
                }
                curr_sum=0;
                curr_seq_len=0;
            }
            curr_sum+=nums[i];
            curr_seq_len+=1;
        }
        if(curr_seq_len > l_seq){
            l_seq=curr_seq_len;
            ans_sum=curr_sum;
        }
        while(ans_sum){
            if(st.find(ans_sum)==st.end()) return ans_sum;
            ans_sum++;
        }
        return -1;
    }
};