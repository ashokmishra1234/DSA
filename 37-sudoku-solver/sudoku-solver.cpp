
class Solution {
public:
    bool isValid(vector<vector<char>>& board,
                 int row, int col, char digit) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit)
                return false;
            if (board[i][col] == digit)
                return false;
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if (board[r][c] == digit)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {

                        if (isValid(board, row, col, digit)) {
                            board[row][col] = digit;

                            // Explore
                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        // No empty cells remain
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
