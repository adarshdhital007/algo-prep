#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        char result=0;

        //XOR
        for(char taylor:s){
            result^=taylor;
        }
        for(char taylor:t){
            result^=taylor;
        }
        return result;

    }
};
int main(){
    Solution sol;
    string s="";
    string t="b";
    //cin>>s>>t;
    char ans=sol.findTheDifference(s,t);
    cout<<ans<<endl;
    return 0;
}
