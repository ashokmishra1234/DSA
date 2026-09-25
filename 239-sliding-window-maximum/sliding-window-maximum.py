class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        q=deque()
        ans=[]
        ind=0
        or_k=k
        while k:
            if ind==0:
                q.append(ind)
            else:
                while q and nums[q[-1]] <= nums[ind]:
                    q.pop()
                q.append(ind)
            ind+=1
            k-=1
        ans.append(nums[q[0]])
        for i in range(or_k,len(nums)):
            while q and  q[0] <= (i-or_k):
                q.popleft()
            while q and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)
            ans.append(nums[q[0]])
        return ans
        