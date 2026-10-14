class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        ans=[]
        s=[]
        def gen(oc,cc,s):
            if oc==0 and cc==0:
                temp="".join(s)
                ans.append(temp)
                return
            if oc<=cc:
                if oc > 0:
                    s.append('(')
                    gen(oc-1,cc,s)
                    s.pop()
                if oc  < cc:
                    s.append(')')
                    gen(oc,cc-1,s)
                    s.pop()
        gen(n,n,s)
        return ans        