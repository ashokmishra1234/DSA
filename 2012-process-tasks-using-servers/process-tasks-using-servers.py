
import heapq

class Solution:
    def assignTasks(self, servers, tasks):

        n = len(servers)
        m = len(tasks)

        ans = [-1] * m

        # Available servers: (weight, index)
        available = []

        # Busy servers: (free_time, weight, index)
        busy = []

        # Initially, all servers are available
        for i in range(n):
            heapq.heappush(available, (servers[i], i))

        curr_time = 0

        for i in range(m):

            # Task i arrives at time i
            curr_time = max(curr_time, i)

            # Move finished servers to available heap
            while busy and busy[0][0] <= curr_time:

                free_time, weight, index = heapq.heappop(busy)

                heapq.heappush(available, (weight, index))

            # If no server is available, wait
            if not available:

                curr_time = busy[0][0]

                # Release all servers free at this time
                while busy and busy[0][0] <= curr_time:

                    free_time, weight, index = heapq.heappop(busy)

                    heapq.heappush(available, (weight, index))

            # Select server with minimum weight and index
            weight, index = heapq.heappop(available)

            ans[i] = index

            # Calculate when this server becomes free
            finish_time = curr_time + tasks[i]

            heapq.heappush(busy, (finish_time, weight, index))

        return ans
