#include<bits/stdc++.h>
using namespace std;

long long max_ad_revenue(vector<int>&price,vector<int>&clicks){
    sort(price.begin(),price.end());
    sort(clicks.begin(),clicks.end());

    vector<long long>c;
    c.reserve(price.size());

    transform(price.begin(),price.end(),clicks.begin(),back_inserter(c),multiplies<long long>());
    long long result=accumulate(c.begin(),c.end(),0ll);
    
    return result;
}
int main(){
    size_t n;
    cin>>n;

    vector<int>price(n),clicks(n);

    for(size_t i=0;i<n;i++){
        cin>>price[i];
    }
    for(size_t i=0;i<n;i++){
        cin>>clicks[i];
    }
    cout<<max_ad_revenue(price,clicks)<<endl;
    return 0;
}