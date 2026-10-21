class StockSpanner:

    def __init__(self):
        self.p=[]
        self.st=[]

    def next(self, price: int) -> int:
        ind=len(self.p)
        while self.st and self.p[self.st[-1]] <= price:
            self.st.pop()
        ans=0
        if self.st:
            ans= ind-self.st[-1]
        else:
            ans= ind+1
        self.p.append(price)
        self.st.append(ind)
        return ans
            


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)