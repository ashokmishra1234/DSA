class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n=len(num)
        st=[]
        for i,ele in enumerate(num):
            while st and st[-1] > ele and k > 0:
                k-=1
                st.pop()
            st.append(ele)
        while st and  k > 0:
            st.pop()
            k-=1
        ans="".join(st)
        ind=0
        for i,ch in enumerate(ans):
            if ch=='0':
                ind+=1
            else:
                 break
        ans=ans[ind:]
        if ans=="":
            return "0"
        return ans