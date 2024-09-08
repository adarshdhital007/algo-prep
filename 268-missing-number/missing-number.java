class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int actualSum = 0;
        int naturalSum = n * (n+1)/2;

        for(int sum :nums){
            actualSum += sum;
        }

        return - actualSum + naturalSum;
    }
}