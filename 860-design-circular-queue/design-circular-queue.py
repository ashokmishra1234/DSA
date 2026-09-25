class MyCircularQueue:
    def __init__(self, k: int):
        self.k = k
        self.nums = [0] * k
        self.head = 0     
        self.count = 0    

    def enQueue(self, value: int) -> bool:
        # Check if full directly
        if self.count == self.k:
            return False
        
        tail = (self.head + self.count) % self.k
        self.nums[tail] = value
        self.count += 1
        return True

    def deQueue(self) -> bool:
        # Check if empty directly
        if self.count == 0:
            return False
        
        self.head = (self.head + 1) % self.k
        self.count -= 1
        return True

    def Front(self) -> int:
        # Check if empty directly
        if self.count == 0:
            return -1
            
        return self.nums[self.head]

    def Rear(self) -> int:
        # Check if empty directly
        if self.count == 0:
            return -1
            
        tail = (self.head + self.count - 1) % self.k
        return self.nums[tail]

    def isEmpty(self) -> bool:
        return self.count == 0

    def isFull(self) -> bool:
        return self.count == self.k

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()