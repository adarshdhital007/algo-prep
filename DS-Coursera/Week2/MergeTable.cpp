#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
	using Collection=vector<int>;
	DisjointSet(istream& is,int N):P(N+1),V{0},M{0}{
		generate(P.begin(),P.end(),[i=-1]() mutable {return ++i;});

		copy_n(istream_iterator<int>(is),N,back_inserter(V));

		M=*max_element(V.begin(),V.end());
	}
	int Union(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b){
			return M;
		}
		P[b]=P[a];
		V[a]+=V[b],V[b]=0;

		if(M<V[a]){
			M=V[a];
		}
		return M;
	}
	int Find(int x){
		if(P[x]==x){
			return P[x];
		}
		return P[x]=Find(P[x]);
	}
private:
	Collection P,V;
	int M;
};

int main(){
	string line;
	auto N{0},M{0};{
		getline(cin,line);
		istringstream is{line};
		is>>N>>M;
	}
	DisjointSet ds{cin,N};
	for(auto a{0},b{0};M--;){
		cin>>a>>b;
		cout<<ds.Union(a,b)<<endl;
	}
	return 0;
}

