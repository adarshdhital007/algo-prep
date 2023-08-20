#include<bits/stdc++.h>
using namespace std;


class DSU{

    int * parent;
    int * rank;
    
    public:
    //Constructor
    DSU(int n){
        parent=new int[n];
        rank=new int[n];

        //Initialize their values by 0 and 1's
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    //Find function
    int find(int node){
        //if the node is parent of itself, then it is the leader of the tree
        if(node==parent[node]){
            return node;
        }
        //else we find parent and also compress the path
        return parent[node]=find(parent[node]);
    }

    void Union(int u,int v){
        //make both leaders
        u=find(u);
        v=find(v);

        //If u and v are not equal,because if they are equal then they are in the same tree and it does not make
       //make sense to do union

       if(u!=v){
        if(rank[u]<rank[v]){
            int temp=u;
            u=v;
            v=temp;
        }
        //Attach lower ranked to higher one
        parent[v]=u;

        //If ranks are equal then increase U,
        if(rank[u]==rank[v]){
            rank[u]++;
        }
       }
    }
};


int main() {
    int n = 6; // Number of elements
    DSU dsu(n);

    dsu.Union(0, 1);
    dsu.Union(1, 2);
    dsu.Union(2, 3);

    // Verify that after unions, find returns the same leader for elements in the same set
    cout << "Find(0) == Find(1): " << (dsu.find(0) == dsu.find(1)) << endl;
    cout << "Find(2) == Find(3): " << (dsu.find(2) == dsu.find(3)) << endl;
    cout << "Find(4) == Find(5): " << (dsu.find(4) == dsu.find(5)) << endl;

    // Verify that path compression is working by printing the leaders after find operations
    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(1): " << dsu.find(1) << endl;
    cout << "Find(2): " << dsu.find(2) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    cout << "Find(4): " << dsu.find(4) << endl;
    cout << "Find(5): " << dsu.find(5) << endl;

    return 0;
}
