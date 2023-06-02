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
    int maximumDetonation(vector<vector<int>>& bombs) {
      map<int,vector<int>>graph;
	  int n=bombs.size();

	 //build the graph
	 F_OR1(n){
		 F_OR2(j,n){
			 if(i==j){
				 continue;
			 }
			 int xi=bombs[i][0],yi=bombs[i][1],ri=bombs[i][2];

			 int xj=bombs[j][0],yj=bombs[j][1];

			 //create a path from node i to node j, if bomb i detonates bomb j
			 if((long)ri*ri>=(long)(xi-xj)*(xi-xj)+(long)(yi-yj)*(yi-yj)){
				 graph[i].pb(j);
			 }
		 }
	 } 
	 int answer=0;
	 F_OR1(n){
		 answer=max(answer,dfs(i,graph));
	 }
	 return answer;
    }

private:
	int dfs(int i,map<int,vector<int>>&graph){
		stack<int>st;
		us<int>visited;
		st.push(i);
		visited.insert(i);
		while(!st.empty()){
			int cur=st.top();
			st.pop();

			for(int neib:graph[cur]){
				if(visited.find(neib)==visited.end()){
					visited.insert(neib);
					st.push(neib);
				}
			}
		}
		return visited.size();
	}
};
int main(){
	Solution solution;
	vector<vector<int>>bombs={
		{1,2,3},{4,5,6},{7,8,9}
	};
	int result=solution.maximumDetonation(bombs);
	print(result);
	return 0;
}

