class Solution {
public:
    bool isPalindrome(int x) {
        long reversed = 0;
        long temp = x;

        if(x < 0)
        return false;

        while(temp != 0){
            int original = temp % 10;
            reversed = reversed * 10 + original;
            temp = temp / 10;
        }
        return (reversed == x);
    }
};