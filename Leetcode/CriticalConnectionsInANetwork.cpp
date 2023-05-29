#include <bits/stdc++.h>
using namespace std;
/*adarshdhital007*/
#define ll long long
#define ld long double
#define ar array
#define um unordered_map
#define us unordered_set
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
    
#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
    
template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 
    
ll FT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)/2;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LT(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)/2;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}
    
template<class A> void rd(vt<A>& v);
template<class A, size_t S> void rd(ar<A, S>& a);
template<class T> void rd(T& x) {
    cin >> x;
}
void rd(double& d) {
    string t;
    rd(t);
    d=stod(t);
}
void rd(long double& d) {
    string t;
    rd(t);
    d=stold(t);
}
template<class H, class... T> void rd(H& h, T&... t) {
    rd(h);
    rd(t...);
}
template<class A> void rd(vt<A>& x) {
    EACH(a, x)
        rd(a);
}
template<class A, size_t S> void rd(array<A, S>& x) {
    EACH(a, x)
        rd(a);
}
    
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}
    
template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
    
template<class A> void wr(A x) {
    cout << to_string(x);
}
template<class H, class... T> void wr(const H& h, const T&... t) { 
    wr(h);
    wr(t...);
}
void print() {
    wr("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    wr(h);
    if(sizeof...(t))
        wr(' ');
    print(t...);
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1}; 

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //adjacency list to represent the graph
        vt<vt<int>>adjList(n);
        //discovery time for each node
        vt<int>disc(n,-1);
        //low-link value for each node
        vt<int>low(n,-1);
        //store the critical connections
        vt<vt<int>>result;

        //build an adjacency list from the given connections
        for(const auto& connection:connections){
            int u=connection[0];
            int v=connection[1];
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        //Tarjan's Algorithm for each unvisited nde
        F_OR1(n){
            if(disc[i]==-1){
                dfs(i,-1,disc,low,adjList,result);
            }
        }
        return result;
    }
private:
        //for tracking discovery time
        int time=0;

        void dfs(int curr, int parent, vt<int>&disc,vt<int>&low,vt<vt<int>>&adjList,vt<vt<int>>&result){
            //Set the discovery time and low link value for current node
            disc[curr]=low[curr]=time++;

            for(int neighbor:adjList[curr]){
                if(neighbor==parent){
                    continue;//skipping the parent in the traversal
                }
                if(disc[neighbor]==-1){
                    //if neighbor not visited yet,make a recursive call
                    dfs(neighbor,curr,disc,low,adjList,result);

                    //update the low link value of the current node
                    low[curr]=min(low[curr],low[neighbor]);
                    
                    //Check if the current edge is a critical connection
                    if(low[neighbor]>disc[curr]){
                        result.pb({curr,neighbor});
                    }
                }
                else{
                    //the neighbor is already visited, so update the low link value to the current node
                    low[curr]=min(low[curr],disc[neighbor]);
                }
            }
        }
};

int main(){
    Solution solution;
    int n=4;
    vt<vt<int>>connections={{0,1},{1,2},{2,0},{1,3}};
    print(solution.criticalConnections(n,connections));
    return 0;
}

 /*
//Tarjan's Algorithm 
Tarjan's algorithm is a graph algorithm used to find strongly connected components (SCCs) in a directed graph.
It was developed by Robert Tarjan and is based on depth-first search (DFS) traversal.

The intuition behind Tarjan's algorithm is to assign a unique identification number (index)
to each node in the graph and maintain a stack of visited nodes during the DFS traversal.
As the DFS traversal progresses, the algorithm keeps track of the minimum index reachable 
from the current node, which helps identify SCCs.

Here is a step-by-step explanation of Tarjan's algorithm:

1.Initialize a unique index counter index to 0 and create an empty stack to store visited nodes.

2.Start a DFS traversal from an arbitrary node v. For each unvisited node encountered, 
perform the following steps:

a. Assign the current node v an index value of index and increment index by 1.

b. Set the low-link value of node v to the same as the index value initially.

c. Push node v onto the stack.

d. Iterate over each neighbor w of node v. If w has not been visited (i.e.,
 it doesn't have an assigned index), recursively call the DFS on w.

e. After the recursive DFS call returns, update the low-link value of node v by
 taking the minimum of its current low-link value and the low-link values of its neighbors.

f. If the index value of node v is equal to its low-link value,
it indicates that node v is the root of a strongly connected component.
Pop nodes from the stack until the current node v is reached,
and each popped node becomes a part of the SCC. 
Store this SCC in a separate data structure or perform some desired operations on it.

3.Repeat step 2 for every unvisited node in the graph until all nodes have been visited.

At the end of the algorithm, you will have identified all the strongly 
connected components present in the graph. The SCCs can be stored in a
data structure or used for further analysis based on your requirements.

Tarjan's algorithm efficiently handles graphs with large numbers of nodes and edges
by using a recursive DFS traversal and maintaining a stack.
It has a time complexity of O(V + E), where V represents the number of nodes (vertices)
in the graph and E represents the number of edges.
*/
