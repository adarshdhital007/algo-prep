class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return (i < n && i >= 0 && j >=0 && j < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
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

                for (auto dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (isSafe(x, y, n, m) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                  return -1;
                }
            }
        }

        return max(0, elapsedTime - 1);
    }
};