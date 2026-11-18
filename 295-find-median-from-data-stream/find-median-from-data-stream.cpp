class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int> max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    if (max_heap.empty() || max_heap.top() >= num) {
        max_heap.push(num);
    } else {
        min_heap.push(num);
    }

    // Rebalance heaps
    if (max_heap.size() > min_heap.size() + 1) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}
    
    double findMedian() {
        int len1=min_heap.size();
        int len2=max_heap.size();
        if((len1+len2)%2){
            return max_heap.top();
        }
        auto ans=(min_heap.top()+max_heap.top())/2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */