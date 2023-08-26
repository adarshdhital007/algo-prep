#include<bits/stdc++.h>
using namespace std;

int majorityelement(vector<int>&nums){
    int candidate=-1;
    int count=0;

    //Find the candidate majority element
    for(int num:nums){
        if(count==0){
            candidate=num;
            count=1;
        }
        else if(num==candidate){count++;}
        else{count--;}
    }
    //Verify the candidate
    count=0;
    for(int num:nums){
        if(num==candidate){
            count++;
        }
    }
    //Check the majority element
    if(count>nums.size()/2){
        return 1;
    }else{return 0;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result=majorityelement(nums);
    cout<<result<<endl;

    return 0;
}