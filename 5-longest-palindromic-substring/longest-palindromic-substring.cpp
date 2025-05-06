class Solution {
public:
    string res = "";
    void expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int val = right - left + 1;
            if (val > res.length()) {
                res = s.substr(left, val);
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) { 
        for(int i=0;i<s.length();i++){
            expand(s,i,i);
            expand(s,i,i + 1);
        }
        
        
        return res; }
};