#include<bits/stdc++.h>
using namespace std;


void partition3(vector<int>&arr,int left, int right,int & middle1, int & middle2){

    int pivot = arr[left];
    middle1=left;
    middle2=left;

    for(int i=left+1;i<=right;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[middle2+1]);
            swap(arr[middle1],arr[middle2+1]);
            middle1++;
            middle2++;
        }
        else if(arr[i]==pivot){
            swap(arr[i],arr[middle2+1]);
            middle2++;
        }
    }
}

void randomizedqs(vector<int>&arr,int left, int right){
    if(left>=right){
        return ;
    }
    int randomIndex=left + rand()% (right-left+1);
    swap(arr[left],arr[randomIndex]);

    int middle1,middle2;
    partition3(arr, left ,right,middle1,middle2);

    randomizedqs(arr,left,middle1-1);
    randomizedqs(arr,middle2+1,right);
}


int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    randomizedqs(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}