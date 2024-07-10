class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for(string &example:logs){
            if(example == "../"){
                depth = max(0,depth -1);
            }else if(example == "./"){
                continue;
            }else{
                depth++;
            }
        }
        return depth;
    }
};