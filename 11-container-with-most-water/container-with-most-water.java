class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;

        int currentArea = 0;
        int maxArea = 0;

        while(left < right){
            currentArea =(int)(Math.min(height[left],height[right]) * (right - left));
            maxArea = Math.max(maxArea, currentArea);

            if(height[left] <= height[right]){
                left++;
            }
            else if(height[left] > height[right]){
                right--;
            }
        }
        return maxArea;
    }
}