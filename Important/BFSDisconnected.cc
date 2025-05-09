#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<int> &res)
{
    int n = adj.size();
    queue<int> q;

    visited[s] = true;
    q.push(s);

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

vector<int> bfsDisconnected(vector<vector<int>> adj)
{
    int V = adj.size();
    vector<int> res;
    vector<bool> visited(V, false);

    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            bfs(adj, i, visited, res);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> adj = {{1, 2}, {0}, {0}, {4}, {3, 5}, {4}};
    vector<int> ans = bfsDisconnected(adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
