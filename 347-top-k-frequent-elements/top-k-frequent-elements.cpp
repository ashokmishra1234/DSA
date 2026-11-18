
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Calculate frequency
        unordered_map<int, int> mp;

        for(auto x : nums) {
            mp[x]++;
        }

        // Step 2: Create a min heap
        // {frequency, element}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Step 3: Insert elements into heap
        for(auto it : mp) {

            int num = it.first;
            int freq = it.second;

            pq.push({freq, num});

            // Maintain heap size <= k
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract k most frequent elements
        vector<int> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
