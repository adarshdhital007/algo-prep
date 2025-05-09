#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> adj)
{
    int n = adj.size();
    int startingIndex = 0;
    vector<int> res;
    vector<bool> visited(n, false);
    queue<int> q;

    visited[startingIndex] = true;
    q.push(startingIndex);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        res.push_back(front);

        for (int x : adj[front])
        {

            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> adj = {{1, 2},
                               {0, 2, 3},
                               {0, 4},
                               {1, 4},
                               {2, 3}};
    vector<int> ans = bfs(adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}