#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int appearsingle(string s){
        unordered_map<int,int>mp;

        //count the character
        for(char demo:s){
            mp[demo]++;
        }

        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    } 
};
int main(){
    Solution sol;
    string s;
    cin>>s;
    int result=sol.appearsingle(s);
    cout<<result<<endl;
    return 0;
}
