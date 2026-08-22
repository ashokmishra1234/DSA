class KthLargest {
public:
    int global_k=0;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        global_k=k;
        for(int i=0;i<nums.size();i++){
            min_heap.push(nums[i]);
        }
        while(!min_heap.empty() && min_heap.size() > k){
            min_heap.pop();
        }
    }
    
    int add(int val) {
        if(min_heap.size() < global_k){
            min_heap.push(val);
            if(min_heap.size() < global_k) return NULL;
            int kth_val=min_heap.top();
            return kth_val;
        }
        int curr_kth_val=min_heap.top();
        if(curr_kth_val >=  val) return curr_kth_val;
        min_heap.pop();
        min_heap.push(val);
        int kth_val=min_heap.top();
        return kth_val;

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */