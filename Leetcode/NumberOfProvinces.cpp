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

 /*
 isConnected = [[1,1,0],[1,1,0],[0,0,1]], province is directly or indirectly connected 
 return : 2
 Approach : Disjoint Set
     1  2  3
1    1  1  0
2    1  1  0
3    0  0  1 
*/

class UnionFind{
public:
    UnionFind(int sz):root(sz),rank(sz),count(sz){
        F_OR1(sz){
            root[i]=i;
            rank[i]=1;

        }
    }
    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }

    void UnionSet(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                root[rootY]=rootX;
            }
            else if(rank[rootX] < rank[rootY]){
                root[rootX]=rootY;
            }
            else {
                root[rootY]=rootX;
                rank[rootX]+=1;
            }
            count --;
        }
    }

    int getCount(){
        return count;
    }
    private:
    vt<int>root;
    vt<int>rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size()==0){
            return 0;
        }
        int n=isConnected.size();
        UnionFind uf(n);
        F_OR1(n){
            F_OR(j,0,n,1){
                if(isConnected[i][j]==1){
                    uf.UnionSet(i,j);
                }
            }
        }
        return uf.getCount();
    }
};

int main(){
    Solution sol;
    vt<vt<int>> connects={{1,1,0},{1,1,0},{0,0,1}};
    int numProvinces=sol.findCircleNum(connects);
    print("Number of provinces : ",numProvinces);
    return 0;
}