#include <bits/stdc++.h>
using namespace std;

class TreeHeight
{
	int n;
	vector<vector<int>> children;
	int root;

public:
	void read()
	{
		cin >> n;
		children.resize(n);
		for (int i = 0; i < n; i++)
		{
			int parent;
			cin >> parent;
			if (parent == -1)
			{
				root = i;
			}
			else
			{
				children[parent].push_back(i);
			}
		}
	}
	int compute(int root)
	{
		int maxHeight = 0;
		for (int i = 0; i < children[root].size(); i++)
		{
			maxHeight = max(maxHeight, compute(children[root][i]));
		}
		return maxHeight + 1;
	}
	int compute_height()
	{
		return compute(root);
	}
};

int main()
{

	TreeHeight tree;
	tree.read();
	cout << (tree.compute_height());
}
