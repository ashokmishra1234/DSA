class Solution:
    def romanToInt(self, s: str) -> int:
        mp={}
        mp['I']=1
        mp['V']=5
        mp['X']=10
        mp['L']=50
        mp['C']=100
        mp['D']=500
        mp['M']=1000
        mp['IV']=4
        mp['IX']=9
        mp['XL']=40
        mp['XC']=90
        mp['CD']=400
        mp['CM']=900
        roman=['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
        ans,i=0,0
        n=len(s)
        while i < n:
            flag=False
            if i+1 < n:
                temp=s[i:i+2]
                if temp in mp:
                    ans+=mp[temp]
                    flag=True
                    i+=2
            if not flag and i < n:
                ans+=mp[s[i]]
                i+=1
        return ans
