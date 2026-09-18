class Solution:
    def longestStrChain(self, words: list[str]) -> int:
        n=len(words)
        words.sort(key=len)
        dp=[1]*n
        parent=[-1]*n
        max_len=1
        for i in range(n):
            parent[i]=i
        for i in range(n):
            word_a=words[i]
            for k in range(len(word_a)):
                prev_word=word_a[:k] + word_a[k+1:]
                for j in range(i):
                    if words[j]==prev_word:
                        if dp[j]+1 > dp[i]:
                            dp[i]=dp[j]+1
                            max_len=max(max_len,dp[i])
        return max_len
                


        