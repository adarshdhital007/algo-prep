class Solution {
public:
    int numberOfChild(int n, int k) {
        int cycleLen = 2 * (n - 1);
        int pos = k % cycleLen;

        if (pos <= n - 1)
            return pos;

        else
            return cycleLen - pos;;
    }
};