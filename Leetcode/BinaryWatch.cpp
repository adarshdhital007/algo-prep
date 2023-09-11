#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>result;
        
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string times=to_string(i)+":";
                    
                    if(j<10){
                        times+='0';
                    }
                    times+=to_string(j);
                    result.push_back(times);
                }
            }
        }
            return result;
        }
};


int main() {
    Solution solution;
    int turnedOn = 1; 
    std::vector<std::string> result = solution.readBinaryWatch(turnedOn);
    
    std::cout << "Possible times with " << turnedOn << " LEDs on the watch: " << std::endl;
    for (const std::string& time : result) {
        std::cout << time << std::endl;
    }
    
    return 0;
}