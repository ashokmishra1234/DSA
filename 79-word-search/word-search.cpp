
class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int index) {

        int m = board.size();
        int n = board[0].size();

        // Successfully matched the entire word
        if(index == word.size())
            return true;

        // Check boundaries
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;

        // Character does not match
        if(board[i][j] != word[index])
            return false;

        // Store original character
        char ch = board[i][j];

        // Mark as visited
        board[i][j] = '#';

        // Explore all four directions
        bool found =
            dfs(board, word, i+1, j, index+1) ||
            dfs(board, word, i-1, j, index+1) ||
            dfs(board, word, i, j+1, index+1) ||
            dfs(board, word, i, j-1, index+1);

        // Backtrack: restore original character
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        // Try starting from every cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
