class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        /*
        [2,1,5,0,4,6]

        f = inf, s = inf

        1. 2 > f, so f = 2 , s = inf
        2. 1 < f, so f = 1 , s = inf
        3. 5 > f and 5 < s, so f = 1, s = 5
        4. 0 < f and 0 < s, so f = 0, s = 5
        5. 4 > 0 and 4 < s , so f = 0, s = 4
        6. 6 > f and 6 > s, so ,[0,4,6]
         */
        for(int i = 0;i<nums.length;i++){
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
}