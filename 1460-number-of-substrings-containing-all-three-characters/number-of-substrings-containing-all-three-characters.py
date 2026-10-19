class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n=len(s)
        i,j=0,0
        mp={}
        ans=0
        for i,ch in enumerate(s):
            if ch=='a':
                mp[ch]=mp.get(ch,0)+1
            elif ch=='b':
                mp[ch]=mp.get(ch,0)+1
            elif ch=='c':
                mp[ch]=mp.get(ch,0)+1
            while j < n and len(mp) >= 3:
                ans+=(n-i)
                mp[s[j]]-=1
                if mp[s[j]]==0:
                    del mp[s[j]]
                j+=1
        return ans
