class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            temp=""
            for i in range(0,len(s),k):
                chunk=s[i:i+k]
                chunk_sum=sum(int(ch) for ch in chunk)
                temp+=str(chunk_sum)
            s=temp
        return s