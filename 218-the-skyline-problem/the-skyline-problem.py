from typing import List
import heapq

class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for L, R, H in buildings:
            events.append((L, -H, R))  # Start: (x, -height, right_end)
            events.append((R, 0, 0))   # End: (x, 0, 0)
        
        events.sort(key=lambda e: (e[0], e[1]))  # Sort x asc, then height desc
        
        result = []
        live_heap = [(0, float('inf'))]  # (-height, right_end)
        prev_max_h = 0
        
        for x, nh, r in events:
            if nh != 0:  # Start building
                heapq.heappush(live_heap, (nh, r))
            
            # Remove expired buildings (right_end <= current x)
            while live_heap[0][1] <= x:
                heapq.heappop(live_heap)
            
            curr_max_h = -live_heap[0][0]
            
            if curr_max_h != prev_max_h:
                result.append([x, curr_max_h])
                prev_max_h = curr_max_h
        
        return result
