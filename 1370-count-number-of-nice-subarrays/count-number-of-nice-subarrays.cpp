class Solution {
public:
    int fun(vector<int> &nums, int k){
        int n=nums.size();
        int ans_cnt=0;
        int odd_cnt=0;
        int l=0,r=0;
        while( r < n){
            if(nums[r]%2) odd_cnt+=1;
            while(odd_cnt > k){
                if(nums[l]%2) odd_cnt-=1;
                l++;
            }
            ans_cnt+=(r-l+1);
            r++;
        }
        return ans_cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt_le_k=fun(nums,k);
        cout<<cnt_le_k<<endl;
        int cnt_le_kminus=fun(nums,k-1);
        cout<<cnt_le_kminus<<endl;
        return cnt_le_k-cnt_le_kminus;
    }
};