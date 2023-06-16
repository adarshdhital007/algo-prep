#include<bits/stdc++.h>
using namespace std;

struct Node{
	long long key;
	int left;
	int right;

	Node():key(0),left(-1),right(-1){}
	Node(long long key_, int left_,int right_):key(key_),left(left_),right(right_){}
	
};

bool isBSTUtil(const vector<Node>& tree, int index,long long min_value,long long max_value){
	if(index==-1)
		return true;

	if(tree[index].key<min_value || tree[index].key>=max_value)
		return false;

	return isBSTUtil(tree,tree[index].left,min_value,tree[index].key)&& isBSTUtil(tree,tree[index].right,tree[index].key,max_value);
}

bool isBST(const vector<Node>& tree){
	if(tree.empty())
		return true;

	long long min_value=LLONG_MIN;
	long long max_value=LLONG_MAX;

	return isBSTUtil(tree,0,min_value,max_value);
}

int main(){
	int n;
	cin>>n;

	vector<Node>tree(n);
	for(int i=0;i<n;i++){
		long long key;
		int left, right;
		cin>>key>>left>>right;
		tree[i]=Node(key,left,right);
	}
	if(isBST(tree))
		cout<<"CORRECT"<<endl;
	else
		cout<<"INCORRECT"<<endl;
	return 0;
}
