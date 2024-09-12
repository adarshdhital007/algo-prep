class Solution {
    public int pivotIndex(int[] nums) {

        int n = nums.length;
        int[] leftSum = new int[n];
        int[] rightSum = new int[n];

        leftSum[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            leftSum[i] = nums[i - 1] + leftSum[i - 1];
        }
        rightSum[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = nums[i + 1] + rightSum[i + 1];
        }
        for (int i = 0; i < nums.length; i++) {

            if (leftSum[i] == rightSum[i]) {
                return i;
            }
        }
        return -1;
    }
}