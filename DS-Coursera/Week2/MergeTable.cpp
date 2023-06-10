#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
	using Collection=vector<int>;
	DisjointSet(istream& is,int N):P(N+1),V
	{}
};

int main(){
	size_t N{0},M{0};{
		string line;
getline(cin,line);
		istringstream parser{line};
		parser>>N>>M;
	}
	using Type=unsigned long long;
	Solution<Type>::Collection A;
	copy_n(istream_iterator<int>(cin),M,back_inserter(A));
	auto ans=Solution<Type>().process(A,N);
	copy(ans.begin(),ans.end(),ostream_iterator<Solution<Type>::Thread>(cout,"\n"));
	return 0;
}
