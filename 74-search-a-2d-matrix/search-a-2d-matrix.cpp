class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = matrix.size();

        int i = 0;
        int j = col - 1;
        // cout << row << "Row" << endl;
        // cout << col << "col" << endl;

        while (i < row && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};