#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int>mp;
        
       for(int i=0;i<s.length();i++){
           
           char c=s[i];
           
          //does the element already exists in the map
           if(mp.find(c)!=mp.end()){
              return c;
           }
           else{
               mp[c]=i;
           }
       }
        return '\0';
    }
};

int main(){
    Solution sol;
    string s;
    cin>>s;
    char result=sol.repeatedCharacter(s);
    cout<<result<<endl;
    return 0;
}