#include<bits/stdc++.h>
using namespace std;

const int M=1000000001;

int main(){
	int n;
	cin>>n;

	unordered_set<int>set;
	int lastsum=0;

	while(n--){
		char op;
		cin>>op;

		if(op=='?'){
			int i;
			cin>>i;
			int num=(i+lastsum)%M;
			cout<<(set.count(num)?"Found":"Not found")<<endl; } else if (op=='+'){
				int i;
				cin>>i;
				int num=(i+lastsum)%M;
				set.insert(num);
			}
		else if(op=='s'){
			int l,r;
			cin>>l>>r;
			int left=(l+lastsum)%M;
			int right=(r+lastsum)%M;

			int sum=0;
			for(int num:set){
				if(left<=num && num<=right){
					sum+=num;
				}
			}
			lastsum=sum;
			cout<<sum<<endl;
		}
	}
	return 0;
}
