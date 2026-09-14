class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0]==1:
            return -1
        n=len(grid)
        dir=[[0,-1],[-1,-1],[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1]]
        pq=[]
        steps=[[float('inf') for _ in range(n)] for _ in range(n)]
        steps[0][0]=1
        heapq.heappush(pq,(0,0,1))
        while pq:
            r,c,step=heapq.heappop(pq)
            if r==n-1 and c==n-1:
                return step
            for it in dir:
                dr=it[0]
                dc=it[1]
                newr=r+dr
                newc=c+dc
                if newr >= 0 and newr < n and newc >=0  and newc < n and grid[newr][newc]==0 and steps[newr][newc] > steps[r][c]+1:
                    steps[newr][newc]=steps[r][c]+1
                    heapq.heappush(pq,(newr,newc,steps[r][c]+1))
        return -1

