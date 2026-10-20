class MinStack:

    def __init__(self):
        self.st = []
        self.min_st = []

    def push(self, value: int) -> None:
        self.st.append(value)
        if not self.min_st or value <= self.min_st[-1]:
            self.min_st.append(value)

    def pop(self) -> None:
        top = self.st.pop()
        if self.min_st and top == self.min_st[-1]:
            self.min_st.pop()

    def top(self) -> int:
        return self.st[-1]

    def getMin(self) -> int:
        return self.min_st[-1]

    def getMin(self) -> int:
        return self.min_st[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()