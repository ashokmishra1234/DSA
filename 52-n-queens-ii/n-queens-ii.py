class Solution:
    def totalNQueens(self, n: int) -> int:
        board = [['.'] * n for _ in range(n)]
        ans=0

        cols = set()
        diag1 = set()  # row - col
        diag2 = set()  # row + col

        def solve(row):
            nonlocal ans
            if row == n:
                ans += 1
                return

            for col in range(n):
                if (col in cols or
                    row - col in diag1 or
                    row + col in diag2):
                    continue

                # Choose
                board[row][col] = 'Q'
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)

                # Explore next row
                solve(row + 1)

                # Undo
                board[row][col] = '.'
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        solve(0)
        return ans
