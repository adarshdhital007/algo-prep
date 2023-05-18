// Minimum Number of Vertices to Reach All Nodes

#include<bits/stdc++.h>
using namespace std;
//template(adarshdhital007)
#define ll long long
#define ld long double
#define ar array

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()


#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
return b<a?a=b, 1:0;
}

template<class T> bool umax(T& a, const T& b) { 
return a<b?a=b, 1:0;
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>hasincomingedge(n,false);
        for(vector<int>&edge:edges){
            hasincomingedge[edge[1]]=true;
        }
       vector<int>requirednodes;
        for(int i=0;i<n;i++){
            //storing all nodes that doesn't have incoming edges

            if(!hasincomingedge[i]){
                requirednodes.push_back(i);
            }
        }
        return requirednodes;
    }
}; 

void solve() {
   Solution solution;
   int n=6;
   vt<vt<int>>edges={{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
   vt<int>result=solution.findSmallestSetOfVertices(n,edges);

   cout<<"Output : ";
   F_OR1(result.size()){
    cout<<result[i]<<" ";
   }
   cout<<endl;
}

int main() {
    solve();
    return 0;
}