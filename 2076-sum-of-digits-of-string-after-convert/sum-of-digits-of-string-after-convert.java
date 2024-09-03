class Solution {
    public int getLucky(String s, int k) {
        Map<Character, Integer> letterMap = new HashMap<>();
        StringBuilder transformed = new StringBuilder();

        for (char i = 'a'; i <= 'z'; i++) {
            letterMap.put(i, i - 'a' + 1);
        }

        // transform into a number
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (letterMap.containsKey(ch)) {
                transformed.append(letterMap.get(ch));
            }
        }

        for (int i = 0; i < k; i++) {
            int totalSum = 0;
            for (int j = 0; j < transformed.length(); j++) {
                totalSum += transformed.charAt(j) - '0';
            }
            transformed = new StringBuilder(Integer.toString(totalSum));
        }
        return Integer.parseInt(transformed.toString());
    }
}