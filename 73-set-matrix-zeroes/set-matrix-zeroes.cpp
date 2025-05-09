class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        unordered_set<int> zeroR;
        unordered_set<int> zeroC;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    zeroR.insert(i);
                    zeroC.insert(j);
                }
            }
        }

        for (int r : zeroR) {
            for (int j = 0; j < col; j++) {
                matrix[r][j] = 0;
            }
        }

        for (int c : zeroC) {
            for (int j = 0; j < row; j++) {
                matrix[j][c] = 0;
            }
        }
    }
};