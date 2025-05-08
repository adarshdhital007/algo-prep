class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() -1;
        int maxValue = 0;

        while(low < high){
            int width = high - low;
            int area = width * min(height[low], height[high]); 

            maxValue = max(area, maxValue);

            if(height[low] < height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxValue;
    }
};