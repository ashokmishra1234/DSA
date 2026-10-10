class Solution:
    def rotate(self, m: list[list[int]]) -> None:
        n = len(m)
        
        # 1. Transpose matrix
        for i in range(n):
            for j in range(i + 1, n):
                m[i][j], m[j][i] = m[j][i], m[i][j]
                
        # 2. Reverse each row
        for r in m:
            r.reverse()