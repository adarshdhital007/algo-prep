class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr;
        for(int i =0;i<nums.size();i++){
            arr.push_back(nums[nums[i]]);
            // cout << nums[nums[i]] << endl;
        }
        return arr;
    }
};