class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        map<int,int,greater<int>> mp;

        for(int i=0;i<k;i++){
            dq.push_front(nums[i]);
            mp[nums[i]]++;
        }
        vector<int> ans;
        auto temp=mp.begin();
        ans.push_back(temp->first);
        for(int i=k;i<n;i++){
            int back_ele=dq.back();
            dq.pop_back();
            mp[back_ele]--;
            if(mp[back_ele]==0) mp.erase(back_ele);
            mp[nums[i]]+=1;
            dq.push_front(nums[i]);
            auto it=mp.begin();
            ans.push_back(it->first);
        }
        return ans;
    }
};