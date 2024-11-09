class Solution {
    public int majorityElement(int[] nums) {
        int bucket = nums[0];
        int count = 1;

        for(int i=1;i<nums.length;i++){
            if(count == 0){
                bucket = nums[i];
                count = 1;
            }else if(bucket == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return bucket;
    }
}