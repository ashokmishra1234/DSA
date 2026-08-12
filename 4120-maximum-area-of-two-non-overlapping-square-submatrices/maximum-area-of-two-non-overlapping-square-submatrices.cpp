class Solution {
public:
    
    int maxArea(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dp1(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(mat[i][j] == 0)
                    continue;

                if(i == 0 || j == 0) {
                    dp1[i][j] = 1;
                }
                else {
                    dp1[i][j] = 1 + min({
                        dp1[i-1][j],
                        dp1[i][j-1],
                        dp1[i-1][j-1]
                    });
                }
            }
        }

        // top[i] = maximum square completely in rows [0...i]
        vector<int> top(rows, 0);

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {
                top[i] = max(top[i], dp1[i][j]);
            }

            if(i > 0)
                top[i] = max(top[i], top[i-1]);
        }


        // dp2[i][j] = largest square starting at (i,j)
        vector<vector<int>> dp2(rows, vector<int>(cols, 0));

        for(int i = rows - 1; i >= 0; i--) {
            for(int j = cols - 1; j >= 0; j--) {

                if(mat[i][j] == 0)
                    continue;

                if(i == rows - 1 || j == cols - 1) {
                    dp2[i][j] = 1;
                }
                else {
                    dp2[i][j] = 1 + min({
                        dp2[i+1][j],
                        dp2[i][j+1],
                        dp2[i+1][j+1]
                    });
                }
            }
        }


        // bottom[i] = maximum square completely in rows [i...rows-1]
        vector<int> bottom(rows, 0);

        for(int i = rows - 1; i >= 0; i--) {

            for(int j = 0; j < cols; j++) {
                bottom[i] = max(bottom[i], dp2[i][j]);
            }

            if(i < rows - 1)
                bottom[i] = max(bottom[i], bottom[i+1]);
        }


        int ans = 0;

        // Horizontal split
        //
        // top:    rows [0 ... i]
        // bottom: rows [i+1 ... rows-1]
        //
        // They cannot overlap.

        for(int i = 0; i < rows - 1; i++) {

            int len = min(top[i], bottom[i+1]);

            ans = max(ans, len);
        }


        // left[j] = maximum square completely in columns [0...j]
        vector<int> left(cols, 0);

        for(int j = 0; j < cols; j++) {

            for(int i = 0; i < rows; i++) {
                left[j] = max(left[j], dp1[i][j]);
            }

            if(j > 0)
                left[j] = max(left[j], left[j-1]);
        }


        // right[j] = maximum square completely in columns [j...cols-1]
        vector<int> right(cols, 0);

        for(int j = cols - 1; j >= 0; j--) {

            for(int i = 0; i < rows; i++) {
                right[j] = max(right[j], dp2[i][j]);
            }

            if(j < cols - 1)
                right[j] = max(right[j], right[j+1]);
        }


        // Vertical split
        //
        // left:  columns [0 ... j]
        // right: columns [j+1 ... cols-1]
        //
        // They cannot overlap.

        for(int j = 0; j < cols - 1; j++) {

            int len = min(left[j], right[j+1]);

            ans = max(ans, len);
        }

        return ans * ans;
    }
};