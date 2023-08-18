#include<bits/stdc++.h>
using namespace std;

vector<int>max_prizes(int n){
    vector<int>prizes;

    if(n<=2){
        return vector<int>({n});
    }

    int k=static_cast<int>(floor(sqrt(n)));

    while(k*(k+1)/2<=n){
        k++;
    }
    k--;
    prizes.reserve(k);
    for(int i=1;i<=k;i++){
        if(i==k){
            prizes.push_back(n);
        }
        else{
            n-=i;
            prizes.push_back(i);
        }
    }
    return prizes;
}
int main(){
    int n;
    cin>>n;

    vector<int> prizes=max_prizes(n);
    cout<<prizes.size()<<'\n';

    for(size_t i=0;i<prizes.size();i++){
        cout<<prizes[i]<<' ';
    }
    return 0;
}