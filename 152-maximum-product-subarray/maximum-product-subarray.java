class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int pf1 = 1;
        int pf2 = 1;
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            if (pf1 == 0) {
                pf1 = nums[i];
            } else {
                pf1 = pf1 * nums[i];
            }
            max1 = Math.max(pf1, max1);
        }

        for (int i = n - 1; i >= 0; i--) {
            if (pf2 == 0) {
                pf2 = nums[i];
            } else {
                pf2 = pf2 * nums[i];
            }
            max2 = Math.max(pf2, max2);
        }
        return Math.max(max1, max2);

    }
}