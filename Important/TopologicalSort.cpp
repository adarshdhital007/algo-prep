#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back

void dfs(vt<vt<int>>& graph, int vertex, vt<bool>& visited, stack<int>& st){
    visited[vertex] = true;

    // Visiting all adjacent vertices
    for(int i = 0; i < graph[vertex].size(); i++){
        int adjacentVertex = graph[vertex][i];
        if(!visited[adjacentVertex]){
            dfs(graph, adjacentVertex, visited, st);
        }
    }
    st.push(vertex);
}

vt<int> topologicalsort(vt<vt<int>>& graph, int numVertices){
    vt<bool> visited(numVertices, false);
    stack<int> st;

    // Performing dfs on each unvisited vertex
    for(int i = 0; i < numVertices; i++){
        if(!visited[i]){
            dfs(graph, i, visited, st);
        }
    }
    
    // Making topological ordering
    vt<int> result;
    while(!st.empty()){
        result.pb(st.top());
        st.pop();
    }
    return result;
}

void solve(){
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vt<vt<int>> graph(numVertices);

    for(int i = 0; i < numEdges; i++){
        int source, destination;
        cin >> source >> destination;
        graph[source - 1].pb(destination - 1);
    }
    
    vt<int> result = topologicalsort(graph, numVertices);
    cout << "Topological Sort :" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << (result[i] + 1);
        if(i < result.size() - 1) cout << " ";
    }
    cout << endl;
}

int main(){
    solve();
    return 0;
}
