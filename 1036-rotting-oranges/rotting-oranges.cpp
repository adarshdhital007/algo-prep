class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int orangesRotting(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<vector<int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2)
                    q.push({i, j});
            }
        }

        int elapsedTime = 0;

        while (!q.empty()) {
            elapsedTime++;

            int len = q.size();
            while (len--) {
                vector<int> curr = q.front();
                q.pop();

                int i = curr[0];
                int j = curr[1];

                for (auto& dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (isSafe(x, y, n, m) && mat[x][y] == 1) {
                        mat[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(mat[i][j] == 1)
                return -1;
            }
        }
        return max(0, elapsedTime - 1);
    }
};