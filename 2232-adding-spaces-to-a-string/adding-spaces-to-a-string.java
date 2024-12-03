class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder str = new StringBuilder();
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            if (j < spaces.length && i == spaces[j]) {
                str.append(' ').append(s.charAt(i));
                j++;
            } else
                str.append(s.charAt(i));
        }
        return str.toString();
    }
}