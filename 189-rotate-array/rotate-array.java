class Solution {
    public void reverse(int[] arr,int low, int high){
        int temp = 0;
        while(low < high){
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;  low++;high--;
        }
    }
    public void rotate(int[] nums, int k) {
        k = k% nums.length;

        reverse(nums,0,nums.length - k - 1);
        reverse(nums,nums.length - k,nums.length - 1);
        reverse(nums,0,nums.length - 1);
    }
}