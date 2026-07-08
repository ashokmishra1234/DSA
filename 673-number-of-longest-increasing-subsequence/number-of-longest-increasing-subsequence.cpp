class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n,1);
        vector<int> count(n,1);
        int maxInd=0,maxlen=0;
        for(int i=0;i<n;i++){
            int temp=0;
            int cnt=1;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(len[i]+len[j] > temp){
                        temp=len[i]+len[j];
                        cnt=max(1,count[j]);
                    }
                    else if(len[i]+len[j]==temp) cnt+=count[j];
                }
            }
            len[i]=temp;
            count[i]=cnt;
            if(len[i] > maxlen){
                maxlen=len[i];
                maxInd=i;
            }
        }
        int tar_len=len[maxInd];
        int ans_cnt=0;
        for(int i=0;i<n;i++){
            if(len[i]==tar_len) ans_cnt+=count[i];
        }
        return ans_cnt;
    }
};