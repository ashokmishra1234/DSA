from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)
        q_r = deque()
        q_d = deque()
        
        # 1. Populate initial indices
        for i, ch in enumerate(senate):
            if ch == 'R':
                q_r.append(i)
            else:
                q_d.append(i)
                
        # 2. Simulate the rounds
        while q_r and q_d:
            # Compare who gets to act first in the current round
            r_idx = q_r.popleft()
            d_idx = q_d.popleft()
            
            # The winner gets pushed to the back of their queue with an updated index
            # adding 'n' simulates them waiting for the next round
            if r_idx < d_idx:
                q_r.append(r_idx + n)
            else:
                q_d.append(d_idx + n)
                
        # 3. Declare victory based on which queue still has members
        return "Radiant" if q_r else "Dire"