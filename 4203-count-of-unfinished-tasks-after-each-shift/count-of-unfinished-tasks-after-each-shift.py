class Solution:
    def countTasks(self, tasks: List[int], shifts: List[int]) -> List[int]:

        task_len = len(tasks)
        shift_len = len(shifts)

        i = 0
        j = 0

        ans = []

        # How much work has already been done
        # on the current task from the previous shift
        prev_shift_time = 0

        # Prefix sum
        pref_sum = [0] * (task_len + 1)

        for k in range(task_len):
            pref_sum[k + 1] = pref_sum[k] + tasks[k]

        while j < shift_len:

            # Total available time for current task sequence
            shift_time = prev_shift_time + shifts[j]

            # Binary search for first unfinished task
            l = i
            r = task_len - 1

            while l <= r:

                mid = l + (r - l) // 2

                # Sum of tasks[i ... mid]
                curr_sum = pref_sum[mid + 1] - pref_sum[i]

                if curr_sum <= shift_time:
                    # Task mid can be completed
                    l = mid + 1
                else:
                    r = mid - 1

            if l == task_len:
                ans.append(0)

                i = 0
                prev_shift_time = 0

            else:
                ans.append(task_len - l)
                completed_work = pref_sum[l] - pref_sum[i]
                prev_shift_time = shift_time - completed_work

                i = l

            j += 1

        return ans
                
