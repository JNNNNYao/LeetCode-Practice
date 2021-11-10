class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool zero_row[m];
        for (int i = 0; i < m; i++) {
            zero_row[i] = false;
        }
        bool zero_col[n];
        for (int i = 0; i < n; i++) {
            zero_col[i] = false;
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    zero_row[r] = true;
                    zero_col[c] = true;
                }
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (zero_row[r] || zero_col[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
        return;
    }
};