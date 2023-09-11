#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:

    bool isIPv4(const string & part){
        if(part.empty() || part.size()>3){
            return false;
        }
        if(part.size()>1 && part[0]=='0'){
            return false;
        }
        int num=0;
        for(char c : part){
            if(!isdigit(c)){
                return "Neither";
            }
            num=num*10+(c-'0');
        }
        return num>=0 && num<=255;
    }
    bool isIPv6(const string & part){

         if(part.empty() || part.size()>4){
            return false;
        }
        for (char c: part){
            if(!isxdigit(tolower(c))){
                return false;
            }
        }
        return true;
    }

    string validIP(string IP){
        //IPV4
            if(count(IP.begin(),IP.end(),'.')==3){
                string part;
                istringstream ss(IP);

                while(getline(ss,part,'.')){
                    if(part.empty() || !isIPv4(part)){
                        return "Neither";
                    }
                }
                if(IP.back()=='.')
                return "Neither";
            return "IPv4";
        }
        //IPv6
        if(count(IP.begin(),IP.end(),':')==7){
            string part;
            istringstream ss(IP);
            while(getline(ss,part,':')){
                if(part.empty() || !isIPv6(part)){
                    return "Neither";
                }
            }
            if(IP.back()==':')
            return "Neither";

            return "IPv6";
        }
        return "Neither";
    }
};
int main(){
    Solution sol;
    string IP;
    cout<<"Enter the IP address  you want to validate : ";
    cin>>IP;

    string result=sol.validIP(IP);
    cout<<"The IP you want to validate is : "<<result<<endl;
    return 0;
}