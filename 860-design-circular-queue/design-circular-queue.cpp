class MyCircularQueue {
public:
    vector<int> q;
    int size=0;
    int cap=0;
    int front=0,rear=-1;
    MyCircularQueue(int k) {
        size=k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(cap == size) return false;
        rear++;
        rear=(rear)%size;
        q[rear]=value;
        cap++;
        return true;
    }
    
    bool deQueue() {
        if(cap == 0) return false;
        front++;
        front=front%size;
        cap--;
        return true;
    }
    
    int Front() {
        if(cap == 0) return -1;
        return q[front];
    }
    
    int Rear() {
        if(cap == 0) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if(cap==0) return true;
        return false;
    }
    
    bool isFull() {
        if(cap==size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */