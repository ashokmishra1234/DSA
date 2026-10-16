class Solution:
    def lemonadeChange(self, bills: list[int]) -> bool:
        n = len(bills)
        mp = {}

        for ele in bills:
            ret_amnt = ele - 5

            if ret_amnt == 0:
                mp[ele] = mp.get(ele, 0) + 1
                continue

            if ret_amnt == 15:
                if mp.get(10, 0) > 0 and mp.get(5, 0) > 0:
                    mp[10] -= 1
                    mp[5] -= 1
                elif mp.get(5, 0) >= 3:
                    mp[5] -= 3
                else:
                    return False

            elif ret_amnt == 5:
                if mp.get(5, 0) > 0:
                    mp[5] -= 1
                else:
                    return False

            elif ret_amnt == 10:
                if mp.get(10, 0) > 0:
                    mp[10] -= 1
                elif mp.get(5, 0) >= 2:
                    mp[5] -= 2
                else:
                    return False

            mp[ele] = mp.get(ele, 0) + 1

        return True
