class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> characterMap;
        int max_length = 0;
        for (int right = 0; right < s.length(); right++) {
            while(characterMap.find(s[right]) != characterMap.end()) {
                characterMap.erase(s[left]);
                left++;
            }
            characterMap.insert(s[right]);
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};