class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> len(n,1),parent(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        int maxLen=0,maxInd=0;
        for(int i=0;i<n;i++){
            int temp=1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(len[i]+len[j] > temp){
                        temp=len[i]+len[j];
                        parent[i]=j;
                    }

                }
            }
            len[i]=temp;
            if(len[i] > maxLen){
                maxLen=len[i];
                maxInd=i;
            }
        }
        vector<int> ans;
        while(parent[maxInd]!=maxInd){
            ans.push_back(nums[maxInd]);
            maxInd=parent[maxInd];
        }
        ans.push_back(nums[maxInd]);
        return ans;
    }
};