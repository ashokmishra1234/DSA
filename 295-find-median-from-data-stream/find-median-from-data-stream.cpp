class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>,greater<int>> min_pq;
    int size=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(size==0) max_pq.push(num);
        else{
            int max_pq_top=max_pq.top();
            if(num > max_pq_top) {
                min_pq.push(num);
                if(min_pq.size() > max_pq.size()){
                    int x=min_pq.top();
                    min_pq.pop();
                    max_pq.push(x);
                }
            }
            else{
                max_pq.push(num);
                if(max_pq.size() > min_pq.size()+1){
                    int x=max_pq.top();
                    max_pq.pop();
                    min_pq.push(x);
                }
            }
        }
        size+=1;
    }
    
    double findMedian() {
        if(size%2) return max_pq.top();
        else return 1.0*(max_pq.top()+min_pq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */