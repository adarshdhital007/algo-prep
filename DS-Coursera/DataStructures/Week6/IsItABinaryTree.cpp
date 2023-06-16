#include<bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	int left;
	int right;
};

bool isBST(int node, const vector<Node>& tree, vector<int>& keys){
	if(node==-1){
		return true;
	}
	if(!isBST(tree[node].left,tree,keys)){
		return false;
	}

	keys.push_back(tree[node].key);

	if(keys.size()>1 && keys[keys.size()-2]>=keys[keys.size()-1]){
		return false;
	}
	if(!isBST(tree[node].right,tree,keys)){
		return false;
	}

	return true;
}
string isBST(const vector<Node>& tree){
	vector<int> keys;
	if(isBST(0,tree,keys)){
		return "CORRECT";
	}
	else
	{
		return "INCORRECT";
  }
}

int main(){
	int n;
	cin>>n;

	vector<Node> tree(n);
	for(int i=0;i<n;i++){
		cin>>tree[i].key>>tree[i].left>>tree[i].right;
	}
	cout<<isBST(tree)<<endl;
	return 0;
}
