#include<bits/stdc++.h>
using namespace std;

int min_refills(int distance,int capacity,vector<int>&fuel_stops){

    if(distance<=capacity){
        return 0;
    }
    int i=0;
    int num_stop=0;
    int current_stop=0;
    int distance_covered=0;
    bool flag=0;

    fuel_stops.push_back(distance);

    while(distance_covered<distance){
        while(i<fuel_stops.size() and fuel_stops[i]-current_stop<=capacity){
            i++;
            flag=true;
        }

        if(flag){
            if(i==fuel_stops.size())break;
            current_stop=fuel_stops[i-1];
            distance_covered=current_stop;
            num_stop+=1;
        }
        else{
            return -1;
        }
        flag=false;
    }
    return num_stop;

}


int main(){
    int d=0;
    cin>>d;
    int m=0;
    cin>>m;
    int n=0;
    cin>>n;

    vector<int>fuel_stops(n);

    for(size_t i=0;i<n;i++){
        cin>>fuel_stops.at(i);
    }
    cout<<min_refills(d,m,fuel_stops)<<"\n";
    return 0;
}